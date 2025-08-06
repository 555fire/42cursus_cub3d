/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:13:55 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 14:33:31 by lchuang          ###   ########.fr       */
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
char		*read_header(int fd, t_game *game, int *flags);
int			count_lines(const char *filename);
int			load_map_lines(int fd, char *first_line, int total_lines,
				t_map_data *d);
int			validate_map(t_game *game);
int			is_map_line(const char *line);
int			parse_header_line(char *line, t_game *game);

void		free_split(char **parts);
int			rpg_to_bit(char *str);
int			put_errmsg(char *msg);
int			put_endmsg(void);
// int			put_stderr(char *msg);

char		*read_line(int fd);
int			convert_map_to_game(t_game *game, t_map_data d);
void		free_game_map_data(t_game *game);

#endif