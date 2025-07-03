/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:28:01 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/03 22:28:02 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sky(t_game *game, int x, int draw_start)
{
	for (int y = 0; y < draw_start; y++)
		draw_pixel(game, x, y, game->ceiling_color);
}

static void	draw_wall_slice(t_game *game, int x, t_texture *tex, t_vslice s)
{
	int	tex_y;
	int	color;

	for (int y = s.draw_start; y <= s.draw_end; y++)
	{
		tex_y = ((int)s.tex_pos) % tex->height;
		if (tex_y < 0)
			tex_y += tex->height;
		color = get_tex_color(tex, s.tex_x, tex_y);
		draw_pixel(game, x, y, color);
		s.tex_pos += s.step_tex;
	}
}

static void	draw_floor_slice(t_game *game, int x, int draw_end)
{
	for (int y = draw_end + 1; y < HEIGHT; y++)
		draw_pixel(game, x, y, game->floor_color);
}

static t_ray	setup_ray(t_game *g, int x)
{
	t_ray	r;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;

	dir_x = cos(g->player.dir);
	dir_y = sin(g->player.dir);
	plane_x = -dir_y * tan(FOV / 2.0);
	plane_y = dir_x * tan(FOV / 2.0);
	camera_x = 2.0 * x / (double)WIDTH - 1.0;
	r.dir_x = dir_x + plane_x * camera_x;
	r.dir_y = dir_y + plane_y * camera_x;
	r.map_x = (int)g->player.x;
	r.map_y = (int)g->player.y;
	r.delta_x = (r.dir_x == 0) ? 1e30 : fabs(1.0 / r.dir_x);
	r.delta_y = (r.dir_y == 0) ? 1e30 : fabs(1.0 / r.dir_y);
	r.step_x = (r.dir_x < 0) ? -1 : 1;
	r.step_y = (r.dir_y < 0) ? -1 : 1;
	r.side_x = (r.dir_x < 0) ? (g->player.x - r.map_x) * r.delta_x : (r.map_x
			+ 1.0 - g->player.x) * r.delta_x;
	r.side_y = (r.dir_y < 0) ? (g->player.y - r.map_y) * r.delta_y : (r.map_y
			+ 1.0 - g->player.y) * r.delta_y;
	return (r);
}

static int	perform_dda(t_game *g, t_ray *r)
{
	int	side;

	side = 0;
	while (r->map_x >= 0 && r->map_x < g->map_width && r->map_y >= 0
		&& r->map_y < g->map_height && g->map[r->map_y][r->map_x] != '1')
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			side = 0;
		}
		else
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			side = 1;
		}
	}
	return (side);
}

static void	draw_column(t_game *game, int x)
{
	t_ray		r;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	t_texture	*wall_tex;
	int			tex_x;
	double		step_tex;
	double		tex_pos;
	t_vslice	slice;

	r = setup_ray(game, x);
	side = perform_dda(game, &r);
	perp_wall_dist = (side == 0) ? (r.map_x - game->player.x + (1 - r.step_x)
			/ 2.0) / r.dir_x : (r.map_y - game->player.y + (1 - r.step_y) / 2.0)
		/ r.dir_y;
	if (perp_wall_dist < 1e-4)
		perp_wall_dist = 1e-4;
	line_height = (int)(HEIGHT / perp_wall_dist);
	if (line_height > HEIGHT)
		line_height = HEIGHT;
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	draw_sky(game, x, draw_start);
	wall_x = (side == 0) ? game->player.y + perp_wall_dist
		* r.dir_y : game->player.x + perp_wall_dist * r.dir_x;
	wall_x -= floor(wall_x);
	wall_tex = (side == 0) ? ((r.dir_x > 0) ? &game->east_tex : &game->west_tex) : ((r.dir_y > 0) ? &game->south_tex : &game->north_tex);
	tex_x = (int)(wall_x * wall_tex->width);
	if ((side == 0 && r.dir_x > 0) || (side == 1 && r.dir_y < 0))
		tex_x = wall_tex->width - tex_x - 1;
	step_tex = (double)wall_tex->height / line_height;
	tex_pos = (draw_start - HEIGHT / 2.0 + line_height / 2.0) * step_tex;
	slice = (t_vslice){draw_start, draw_end, tex_x, step_tex, tex_pos};
	draw_wall_slice(game, x, wall_tex, slice);
	draw_floor_slice(game, x, draw_end);
}

void	draw_walls(t_game *game)
{
	for (int x = 0; x < WIDTH; x++)
		draw_column(game, x);
}

int	render(t_game *game)
{
	draw_walls(game);
	return (0);
}