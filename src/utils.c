/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:28:06 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/03 22:28:07 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line,
			&tex->endian);
	return (1);
}

int	get_tex_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= tex->width || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->size_line + x * (tex->bpp / 8));
	return (*(int *)pixel);
}

void	draw_pixel(t_game *game, int x, int y, int color)
{
	mlx_pixel_put(game->mlx, game->win, x, y, color);
}