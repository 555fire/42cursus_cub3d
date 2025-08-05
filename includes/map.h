/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:13:55 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/05 16:04:13 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"
# include "structs.h"

# define ID_NO 1
# define ID_SO 2
# define ID_WE 4
# define ID_EA 8
# define ID_F 16
# define ID_C 32

typedef struct s_map_data
{
	char	**lines;
	int		count;
	int		width;
}			t_map_data;

int			parse_map_from_file(const char *filename, t_game *game);
int			read_header(int fd, t_game *game, int *flags);
int			count_lines(const char *filename);
int			load_map_lines(int fd, int total_lines, t_map_data *d);
int			validate_map(t_game *game);
int			is_map_line(const char *line);
int			parse_header_line(char *line, t_game *game);

void		free_split(char **parts);
int			rpg_to_bit(char *str);
int			put_stderr(char *msg);
// int			put_stderr(char *msg);

char		*read_line(int fd);

#endif