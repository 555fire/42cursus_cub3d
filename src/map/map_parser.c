/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:14:23 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/04 17:14:13 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_map_line(const char *line)
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

static int	parse_texture_line_ns(char *line, t_game *game)
{
	char	**dest;
	int		id;
	char	*path_start;

	dest = NULL;
	id = 0;
	path_start = NULL;
	if (!ft_strncmp(line, "NO ", 3))
	{
		dest = &game->north_path;
		id = ID_NO;
		path_start = line + 3;
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		dest = &game->south_path;
		id = ID_SO;
		path_start = line + 3;
	}
	else
		return (0);
	if (*dest)
		return (-1);
	*dest = ft_strdup(path_start);
	return (id);
}

static int	parse_texture_line_we(char *line, t_game *game)
{
	char	**dest;
	int		id;
	char	*path_start;

	dest = NULL;
	id = 0;
	path_start = NULL;
	if (!ft_strncmp(line, "WE ", 3))
	{
		dest = &game->west_path;
		id = ID_WE;
		path_start = line + 3;
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		dest = &game->east_path;
		id = ID_EA;
		path_start = line + 3;
	}
	else
		return (0);
	if (*dest)
		return (-1);
	*dest = ft_strdup(path_start);
	return (id);
}

static int	parse_color_line(char *line, t_game *game)
{
	int	col;

	if (!ft_strncmp(line, "F ", 2))
	{
		if (game->floor_color != -1)
			return (-1);
		col = rpg_to_bit(line + 2);
		if (col < 0)
			return (-2);
		game->floor_color = col;
		return (ID_F);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (game->ceiling_color != -1)
			return (-1);
		col = rpg_to_bit(line + 2);
		if (col < 0)
			return (-2);
		game->ceiling_color = col;
		return (ID_C);
	}
	return (0);
}

int	parse_header_line(char *line, t_game *game)
{
	int	ret;

	ret = parse_texture_line_ns(line, game);
	if (ret)
		return (ret);
	ret = parse_texture_line_we(line, game);
	if (ret)
		return (ret);
	ret = parse_color_line(line, game);
	if (ret)
		return (ret);
	if (*line == '\0')
		return (0);
	return (-3);
}
