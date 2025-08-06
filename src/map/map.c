/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:14:11 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06
 12:15:49 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	alloc_game_map(t_game *game, int map_count, int map_width)
{
	int	i;
	int	j;

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
			game->map = NULL;
			return (0);
		}
		ft_memset(game->map[i], ' ', map_width);
		game->map[i][map_width] = '\0';
		i++;
	}
	game->map[map_count] = NULL;
	return (1);
}

static int	convert_map_to_game(t_game *game, t_map_data d)
{
	int	i;

	game->map_height = d.count;
	game->map_width = d.width;
	if (!alloc_game_map(game, d.count, d.width))
		return (0);
	i = 0;
	while (i < d.count)
	{
		ft_memcpy(game->map[i], d.lines[i], ft_strlen(d.lines[i]));
		free(d.lines[i]);
		i++;
	}
	free(d.lines);
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

static int	open_and_validate_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCannot open file %s\n", filename), -1);
	return (fd);
}

static char	*process_map_header(int fd, t_game *game)
{
	char	*first_map_line;
	int		flags;

	flags = 0;
	game->floor_color = -1;
	game->ceiling_color = -1;
	first_map_line = read_header(fd, game, &flags);
	if (!first_map_line)
	{
		put_errmsg("Invalid file format or missing map content.");
		return (NULL);
	}
	if (flags != (ID_NO | ID_SO | ID_WE | ID_EA | ID_F | ID_C))
	{
		free(first_map_line);
		put_errmsg("Missing header elements");
		return (NULL);
	}
	return (first_map_line);
}

static int	load_and_process_map_content(int fd, const char *filename,
		char *first_map_line, t_map_data *map_data)
{
	int	total_lines;

	total_lines = count_lines(filename);
	if (total_lines < 0)
	{
		free(first_map_line);
		return (0);
	}
	if (!load_map_lines(fd, first_map_line, total_lines, map_data))
	{
		return (0);
	}
	return (1);
}

static int	load_map_data(const char *filename, t_game *game,
		t_map_data *map_data)
{
	int		fd;
	char	*first_map_line;

	fd = open_and_validate_file(filename);
	if (fd < 0)
		return (0);
	first_map_line = process_map_header(fd, game);
	if (!first_map_line)
	{
		close(fd);
		return (0);
	}
	if (!load_and_process_map_content(fd, filename, first_map_line, map_data))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	parse_map_from_file(const char *filename, t_game *game)
{
	t_map_data	map_data;

	if (!load_map_data(filename, game, &map_data))
		return (0);
	if (!convert_map_to_game(game, map_data))
		return (0);
	if (!validate_map(game))
	{
		free_game_map_data(game);
		return (0);
	}
	return (1);
}
