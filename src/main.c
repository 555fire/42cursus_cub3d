/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:26:00 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 08:45:27 by lchuang          ###   ########.fr       */
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

static int	init_game_from_file(char *path, t_game *game)
{
	ft_memset(game, 0, sizeof(*game));
	if (!parse_map_from_file(path, game))
		return (0);
	init_player(game);
	return (1);
}

static int	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!load_texture(game, &game->north_tex, game->north_path)
		|| !load_texture(game, &game->south_tex, game->south_path)
		|| !load_texture(game, &game->east_tex, game->east_path)
		|| !load_texture(game, &game->west_tex, game->west_path)){
		return (put_errmsg("load_texture failed"));
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D - Minimap");
	return (game->win != NULL);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (put_errmsg("Invalid input"), 1);
	if (!init_game_from_file(argv[1], &game) || !init_graphics(&game))
	{
		// fprintf(stderr, "Error\n");
		cleanup_game(&game);
		return (1);
	}
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 1L << 17, handle_close, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	put_endmsg();
	return (0);
}
