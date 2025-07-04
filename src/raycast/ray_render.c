/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:58:41 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/04 10:12:05 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	draw_sky(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, game->ceiling_color);
		y++;
	}
}

static int	get_tex_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= tex->width || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->size_line + x * (tex->bpp / 8));
	return (*(int *)pixel);
}

static void	draw_wall_slice(t_game *game, int x, t_texture *tex, t_vslice s)
{
	int	y;
	int	tex_y;
	int	color;

	y = s.draw_start;
	while (y <= s.draw_end)
	{
		tex_y = ((int)s.tex_pos) % tex->height;
		if (tex_y < 0)
			tex_y += tex->height;
		color = get_tex_color(tex, s.tex_x, tex_y);
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		s.tex_pos += s.step_tex;
		y++;
	}
}

static void	draw_floor_slice(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end + 1;
	while (y < HEIGHT)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, game->floor_color);
		y++;
	}
}

void	draw_column(t_game *game, int x)
{
	t_ray			r;
	int				side;
	t_column_params	p;
	t_vslice		s;

	r = setup_ray(game, x);
	side = perform_dda(game, &r);
	calc_line_params(game, &r, side, &p);
	calc_texture_params(game, &r, side, &p);
	draw_sky(game, x, p.draw_start);
	s = (t_vslice){p.draw_start, p.draw_end, p.tex_x, p.step_tex,
		p.tex_pos};
	draw_wall_slice(game, x, p.tex, s);
	draw_floor_slice(game, x, p.draw_end);
}
