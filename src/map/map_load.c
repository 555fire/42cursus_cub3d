/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:13:20 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/05 16:05:42 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		ret;

	line = malloc(MAX_LINE);
	if (!line)
		return (NULL);
	i = 0;
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n')
	{
		if (i < MAX_LINE - 1)
			line[i++] = c;
		ret = read(fd, &c, 1);
	}
	line[i] = '\0';
	if (ret <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot open file %s\n", filename);
		return (-1);
	}
	count = 0;
	line = read_line(fd);
	while (line != NULL)
	{
		if (is_map_line(line))
			count++;
		free(line);
		line = read_line(fd);
	}
	close(fd);
	return (count);
}

static void	store_map_line(char *line, char **map_lines, t_map_data *data)
{
	int	len;

	map_lines[data->count] = line;
	len = ft_strlen(line);
	if (len > data->width)
		data->width = len;
	data->count++;
}

static int	read_map_lines_loop(int fd, char **map_lines, t_map_data *data)
{
	char	*line;

	line = read_line(fd);
	while (line)
	{
		if (is_map_line(line))
			store_map_line(line, map_lines, data);
		else
			free(line);
		line = read_line(fd);
	}
	return (data->count > 0);
}

int	load_map_lines(int fd, int total_lines, t_map_data *map_data)
{
	char	**map_lines;

	map_lines = malloc(sizeof(char *) * (total_lines + 1));
	if (!map_lines)
		return (0);
	map_data->count = 0;
	map_data->width = 0;
	if (!read_map_lines_loop(fd, map_lines, map_data))
	{
		free(map_lines);
		return (0);
	}
	map_lines[map_data->count] = NULL;
	map_data->lines = map_lines;
	return (1);
}
