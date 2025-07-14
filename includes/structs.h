/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:07:44 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/14 11:09:14 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_column_params
{
	double		perp_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_texture	*tex;
	int			tex_x;
	double		step_tex;
	double		tex_pos;
}				t_column_params;

#endif