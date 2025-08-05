/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:31:35 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/05 16:04:13 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	add_header_element(char *line, t_game *game, int *flags)
{
	int	id;

	id = parse_header_line(line, game);
	if (id < 0)
		return (put_stderr("Invalid or duplicate header element"));
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
