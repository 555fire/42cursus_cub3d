/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:14:23 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 09:07:58 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*get_path_from_line(char *line, const char *prefix)
{
	char	*path_start;
	size_t	prefix_len;

	prefix_len = ft_strlen(prefix);
	if (ft_strncmp(line, prefix, prefix_len) == 0
		&& (line[prefix_len] == ' ' || line[prefix_len] == '\t'))
	{
		path_start = line + prefix_len;
		while (*path_start && (*path_start == ' ' || *path_start == '\t'))
			path_start++;
		return (ft_strdup(path_start));
	}
	return (NULL);
}

static int	set_texture(char **texture_path, char *path, int id)
{
	if (*texture_path)
	{
		free(path);
		return (-1);
	}
	*texture_path = path;
	return (id);
}

static int	parse_texture_line(char *line, t_game *game)
{
	char	*path;

	path = get_path_from_line(line, "NO");
	if (path)
		return (set_texture(&game->north_path, path, ID_NO));
	path = get_path_from_line(line, "SO");
	if (path)
		return (set_texture(&game->south_path, path, ID_SO));
	path = get_path_from_line(line, "WE");
	if (path)
		return (set_texture(&game->west_path, path, ID_WE));
	path = get_path_from_line(line, "EA");
	if (path)
		return (set_texture(&game->east_path, path, ID_EA));
	return (0);
}

static int	set_color(int *game_color, char *value_str, int id)
{
	int	color_val;

	if (*game_color != -1)
	{
		free(value_str);
		return (-1);
	}
	color_val = rpg_to_bit(value_str);
	free(value_str);
	if (color_val < 0)
		return (-2);
	*game_color = color_val;
	return (id);
}

int	parse_header_line(char *line, t_game *game)
{
	int		ret;
	char	*value_str;

	ret = parse_texture_line(line, game);
	if (ret)
		return (ret);
	value_str = get_path_from_line(line, "F");
	if (value_str)
		return (set_color(&game->floor_color, value_str, ID_F));
	value_str = get_path_from_line(line, "C");
	if (value_str)
		return (set_color(&game->ceiling_color, value_str, ID_C));
	if (*line == '\0')
		return (0);
	return (-3);
}
