/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:08:20 by lchuang           #+#    #+#             */
/*   Updated: 2025/06/17 15:23:03 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode)
{
	if (keycode == ESC_KEY)
	{
		exit(0);
	}
	return (0);
}

int	handle_close(void)
{
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	if (argc != 2)
	{
		write(2, "Usage: ./cub3d <map.cub>\n", 26);
		return (1);
	}
	parse_cub(argv[1]);
	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
	if (!win)
		return (1);
	img = mlx_xpm_file_to_image(mlx, "textures/test.xpm", &img_width,
			&img_height);
	if (!img)
		return (1);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, handle_key, NULL);
	mlx_hook(win, 17, 0, handle_close, NULL);
	mlx_loop(mlx);
	return (0);
}
