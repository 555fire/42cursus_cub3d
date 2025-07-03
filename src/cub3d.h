/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:50:37 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/03 22:30:08 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 640
# define HEIGHT 480
# define TITLE "cub3d test window"
# define MAX_LINE 1024

# define ESC_KEY 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define MOVE_SPEED 0.5
# define ROT_SPEED 0.1

# define TILE_SIZE 10
# define FOV (M_PI / 3)

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
}				t_player;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_x;
	double		delta_y;
	int			step_x;
	int			step_y;
	double		side_x;
	double		side_y;
}				t_ray;

typedef struct s_vslice
{
	int			draw_start;
	int			draw_end;
	int			tex_x;
	double		step_tex;
	double		tex_pos;
}				t_vslice;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	void		*mlx;
	void		*win;
	t_texture	north_tex;
	t_texture	south_tex;
	t_texture	east_tex;
	t_texture	west_tex;
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	int			floor_color;
	int			ceiling_color;
}				t_game;

int				parse_map_from_file(const char *filename, t_game *game);
void			init_player(t_game *game);
int				load_texture(t_game *game, t_texture *tex, char *path);
int				get_tex_color(t_texture *tex, int x, int y);
void			draw_pixel(t_game *game, int x, int y, int color);
void			cleanup_game(t_game *game);
int				handle_key(int keycode, t_game *game);
int				handle_close(t_game *game);
int				render(t_game *game);

#endif