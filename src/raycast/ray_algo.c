/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:58:29 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/04 10:53:00 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_ray_params(t_game *g, t_ray *r)
{
	if (r->dir_x == 0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1.0 / r->dir_x);
	if (r->dir_y == 0)
		r->delta_y = 1e30;
	else
		r->delta_y = fabs(1.0 / r->dir_y);
	if (r->dir_x < 0)
		r->step_x = -1;
	else
		r->step_x = 1;
	if (r->dir_y < 0)
		r->step_y = -1;
	else
		r->step_y = 1;
	if (r->dir_x < 0)
		r->side_x = (g->player.x - r->map_x) * r->delta_x;
	else
		r->side_x = (r->map_x + 1.0 - g->player.x) * r->delta_x;
	if (r->dir_y < 0)
		r->side_y = (g->player.y - r->map_y) * r->delta_y;
	else
		r->side_y = (r->map_y + 1.0 - g->player.y) * r->delta_y;
}

t_ray	setup_ray(t_game *g, int x)
{
	t_ray	r;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	dir_x = cos(g->player.dir);
	dir_y = sin(g->player.dir);
	plane_x = -dir_y * tan(FOV / 2.0);
	plane_y = dir_x * tan(FOV / 2.0);
	r.dir_x = dir_x + plane_x * (2.0 * x / (double)WIDTH - 1.0);
	r.dir_y = dir_y + plane_y * (2.0 * x / (double)WIDTH - 1.0);
	r.map_x = (int)g->player.x;
	r.map_y = (int)g->player.y;
	init_ray_params(g, &r);
	return (r);
}

int	perform_dda(t_game *g, t_ray *r)
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

void	calc_line_params(t_game *g, t_ray *r, int side, t_column_params *p)
{
	double	perp_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	if (side == 0)
		perp_dist = (r->map_x - g->player.x + (1 - r->step_x) / 2.0) / r->dir_x;
	else
		perp_dist = (r->map_y - g->player.y + (1 - r->step_y) / 2.0) / r->dir_y;
	if (perp_dist < 1e-4)
		perp_dist = 1e-4;
	line_height = (int)(HEIGHT / perp_dist);
	if (line_height > HEIGHT)
		line_height = HEIGHT;
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	p->perp_dist = perp_dist;
	p->line_height = line_height;
	p->draw_start = draw_start;
	p->draw_end = draw_end;
}

void	calc_texture_params(t_game *g, t_ray *r, int side, t_column_params *p)
{
	double		wall_x;
	t_texture	*wall_tex;
	int			tex_x;

	if (side == 0)
		wall_x = g->player.y + p->perp_dist * r->dir_y;
	else
		wall_x = g->player.x + p->perp_dist * r->dir_x;
	wall_x -= floor(wall_x);
	if (side == 0 && r->dir_x > 0)
		wall_tex = &g->east_tex;
	else if (side == 0 && !(r->dir_x > 0))
		wall_tex = &g->west_tex;
	if (side != 0 && r->dir_y > 0)
		wall_tex = &g->south_tex;
	else if (side != 0 && !(r->dir_y > 0))
		wall_tex = &g->north_tex;
	tex_x = (int)(wall_x * wall_tex->width);
	if ((side == 0 && r->dir_x > 0) || (side == 1 && r->dir_y < 0))
		tex_x = wall_tex->width - tex_x - 1;
	p->tex = wall_tex;
	p->tex_x = tex_x;
	p->step_tex = (double)wall_tex->height / p->line_height;
	p->tex_pos = (p->draw_start - HEIGHT / 2.0 + p->line_height / 2.0)
		* p->step_tex;
}
