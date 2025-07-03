/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:26:00 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/03 22:27:24 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		fprintf(stderr, "Error!\n");
		return (1);
	}
	memset(&game, 0, sizeof(game));
	game.floor_color = 0x222222;
	game.ceiling_color = 0x87CEEB;

	if (!parse_map_from_file(argv[1], &game))
	{
		fprintf(stderr, "Error!\n");
		return (1);
	}
	init_player(&game);

	game.mlx = mlx_init();
	if (!game.mlx)
	{
		cleanup_game(&game);
		return (1);
	}
	if (!load_texture(&game, &game.north_tex, game.north_path)
		|| !load_texture(&game, &game.south_tex, game.south_path)
		|| !load_texture(&game, &game.east_tex, game.east_path)
		|| !load_texture(&game, &game.west_tex, game.west_path))
	{
		fprintf(stderr, "Error!\n");
		cleanup_game(&game);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "cub3D - Minimap");
	if (!game.win)
	{
		cleanup_game(&game);
		return (1);
	}
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 1L << 17, handle_close, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}