/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:25:58 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 00:00:11 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_game(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->north_tex.img)
		mlx_destroy_image(game->mlx, game->north_tex.img);
	if (game->south_tex.img)
		mlx_destroy_image(game->mlx, game->south_tex.img);
	if (game->east_tex.img)
		mlx_destroy_image(game->mlx, game->east_tex.img);
	if (game->west_tex.img)
		mlx_destroy_image(game->mlx, game->west_tex.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

int	handle_close(t_game *game)
{
	cleanup_game(game);
	put_endmsg();
	exit(0);
	return (0);
}
