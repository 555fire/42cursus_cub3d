/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:03:35 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/04 11:02:06 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ID_NO 1
#define ID_SO 2
#define ID_WE 4
#define ID_EA 8
#define ID_F 16
#define ID_C 32

static char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		ret;

	line = malloc(MAX_LINE);
	if (!line)
		return (NULL);
	i = 0;
	while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
	{
		if (i < MAX_LINE - 1)
			line[i++] = c;
	}
	line[i] = '\0';
	if (ret <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i])
		return (0);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_color_value(char *str)
{
	int r, g, b;
	if (sscanf(str, "%d,%d,%d", &r, &g, &b) != 3)
		return (-1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

static int	error_msg(const char *msg)
{
	fprintf(stderr, "Error\n%s\n", msg);
	return (0);
}

static int	parse_header_line(char *line, t_game *game)
{
	int	col;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (game->north_path)
			return (-1);
		game->north_path = strdup(line + 3);
		return (ID_NO);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (game->south_path)
			return (-1);
		game->south_path = strdup(line + 3);
		return (ID_SO);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (game->west_path)
			return (-1);
		game->west_path = strdup(line + 3);
		return (ID_WE);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (game->east_path)
			return (-1);
		game->east_path = strdup(line + 3);
		return (ID_EA);
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->floor_color != -1)
			return (-1);
		col = parse_color_value(line + 2);
		if (col < 0)
			return (-2);
		game->floor_color = col;
		return (ID_F);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->ceiling_color != -1)
			return (-1);
		col = parse_color_value(line + 2);
		if (col < 0)
			return (-2);
		game->ceiling_color = col;
		return (ID_C);
	}
	else if (*line == '\0')
		return (0);
	return (-3);
}

static int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Cannot open file %s\n", filename);
		return (-1);
	}
	count = 0;
	while ((line = read_line(fd)) != NULL)
	{
		if (is_map_line(line))
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

static int	validate_map(t_game *game)
{
	int		player_cnt;
	char	c;
	int		y;
	int		x;

	player_cnt = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			c = game->map[y][x];
			if (c == ' ')
			{
				x++;
				continue ;
			}
			if (c == '0' || strchr("NSEW", c))
			{
				if (y == 0 || y == game->map_height - 1 || x == 0
					|| x == game->map_width - 1)
					return (error_msg("Map not enclosed by walls"));
				if (game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' '
					|| game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' ')
					return (error_msg("Map has open space"));
				if (strchr("NSEW", c))
					player_cnt++;
			}
			else if (c != '1')
				return (error_msg("Invalid character in map"));
			x++;
		}
		y++;
	}
	if (player_cnt != 1)
		return (error_msg("Map must contain exactly one player start"));
	return (1);
}

static int	read_header(int fd, t_game *game, int *flags)
{
	char	*line;
	int		id;
	int		header_done;

	header_done = 0;
	while (!header_done)
	{
		line = read_line(fd);
		if (!line)
			break ;
		if (is_map_line(line))
		{
			lseek(fd, -(long)(strlen(line) + 1), SEEK_CUR);
			free(line);
			header_done = 1;
			continue ;
		}
		id = parse_header_line(line, game);
		if (id < 0)
		{
			free(line);
			return (error_msg("Invalid or duplicate header element"));
		}
		*flags |= id;
		free(line);
	}
	return (1);
}

static int	load_map_lines(int fd, int total_lines, char ***map_lines_out,
		int *count_out, int *max_width_out)
{
	char	*line;
	char	**map_lines;

	map_lines = malloc(sizeof(char *) * (total_lines + 1));
	if (!map_lines)
		return (0);
	*count_out = 0;
	*max_width_out = 0;
	while ((line = read_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			map_lines[*count_out] = line;
			if ((int)strlen(line) > *max_width_out)
				*max_width_out = strlen(line);
			(*count_out)++;
		}
		else
			free(line);
	}
	if (*count_out == 0)
	{
		free(map_lines);
		return (0);
	}
	map_lines[*count_out] = NULL;
	*map_lines_out = map_lines;
	return (1);
}

static int	convert_map_to_game(t_game *game, char **map_lines, int map_count,
		int map_width)
{
	int	i;
	int	j;

	game->map_height = map_count;
	game->map_width = map_width;
	game->map = malloc(sizeof(char *) * (map_count + 1));
	if (!game->map)
		return (0);
	i = 0;
	while (i < map_count)
	{
		game->map[i] = malloc(sizeof(char) * (map_width + 1));
		if (!game->map[i])
		{
			j = i;
			while (--j >= 0)
				free(game->map[j]);
			free(game->map);
			return (0);
		}
		memset(game->map[i], ' ', map_width);
		memcpy(game->map[i], map_lines[i], strlen(map_lines[i]));
		game->map[i][map_width] = '\0';
		free(map_lines[i]);
		i++;
	}
	game->map[map_count] = NULL;
	free(map_lines);
	return (1);
}

static void	free_game_map_data(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
}

int	parse_map_from_file(const char *filename, t_game *game)
{
	int		fd;
	int		flags;
	int		total_lines;
	char	**map_lines;
	int		map_count;
	int		map_width;

	flags = 0;
	game->floor_color = -1;
	game->ceiling_color = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error: Cannot open file %s\n", filename), 0);
	if (!read_header(fd, game, &flags))
		return (close(fd), 0);
	if (flags != (ID_NO | ID_SO | ID_WE | ID_EA | ID_F | ID_C))
		return (close(fd), error_msg("Missing header elements"));
	total_lines = count_lines(filename);
	if (total_lines < 0)
		return (close(fd), 0);
	if (!load_map_lines(fd, total_lines, &map_lines, &map_count, &map_width))
		return (close(fd), 0);
	close(fd);
	if (!convert_map_to_game(game, map_lines, map_count, map_width))
		return (0);
	if (!validate_map(game))
	{
		free_game_map_data(game);
		return (0);
	}
	return (1);
}
