/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:31:35 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 09:08:03 by lchuang          ###   ########.fr       */
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

static int	add_header_element(char *line, t_game *game, int *flags)
{
	int	id;

	id = parse_header_line(line, game);
	if (id < 0)
		return (put_errmsg("Invalid or duplicate header element"));
	*flags |= id;
	return (1);
}

static int	skip_map_line(int fd, char *line)
{
	if (!is_map_line(line))
		return (0);
	lseek(fd, -(long)(ft_strlen(line) + 1), SEEK_CUR);
	return (1);
}

int	read_header(int fd, t_game *game, int *flags)
{
	char	*line;

	while (1)
	{
		line = read_line(fd);
		if (!line)
			break ;
		if (skip_map_line(fd, line))
		{
			free(line);
			break ;
		}
		if (!add_header_element(line, game, flags))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
