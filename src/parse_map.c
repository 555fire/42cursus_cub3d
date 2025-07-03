/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:03:35 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/03 22:29:30 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	parse_header_line(char *line, t_game *game)
{
	int	col;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		game->north_path = strdup(line + 3);
		return (1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		game->south_path = strdup(line + 3);
		return (1);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		game->west_path = strdup(line + 3);
		return (1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		game->east_path = strdup(line + 3);
		return (1);
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		col = parse_color_value(line + 2);
		if (col < 0)
			return (0);
		game->floor_color = col;
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		col = parse_color_value(line + 2);
		if (col < 0)
			return (0);
		game->ceiling_color = col;
		return (1);
	}
	return (0);
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

int	parse_map_from_file(const char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**map_lines;
	int		map_count;
	int		i;
	int		total_lines;
	int		header_done;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Cannot open file %s\n", filename);
		return (0);
	}
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
			break ;
		}
		if (!parse_header_line(line, game))
		{
			free(line);
		}
		else
			free(line);
	}
	total_lines = count_lines(filename);
	if (total_lines < 0)
	{
		close(fd);
		return (0);
	}
	map_lines = malloc(sizeof(char *) * (total_lines + 1));
	if (!map_lines)
	{
		close(fd);
		return (0);
	}
	map_count = 0;
	game->map_width = 0;
	while ((line = read_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			map_lines[map_count] = line;
			if ((int)strlen(line) > game->map_width)
				game->map_width = strlen(line);
			map_count++;
		}
		else
		{
			free(line);
		}
	}
	close(fd);
	if (map_count == 0)
	{
		free(map_lines);
		return (0);
	}
	game->map_height = map_count;
	game->map = malloc(sizeof(char *) * (map_count + 1));
	if (!game->map)
	{
		for (i = 0; i < map_count; i++)
			free(map_lines[i]);
		free(map_lines);
		return (0);
	}
	for (i = 0; i < map_count; i++)
	{
		game->map[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[i])
		{
			while (--i >= 0)
				free(game->map[i]);
			free(game->map);
			for (i = 0; i < map_count; i++)
				free(map_lines[i]);
			free(map_lines);
			return (0);
		}
		strcpy(game->map[i], map_lines[i]);
		free(map_lines[i]);
	}
	game->map[map_count] = NULL;
	free(map_lines);
	return (1);
}
