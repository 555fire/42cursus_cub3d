/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:27:58 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/03 22:27:59 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (strchr("NSEW", game->map[y][x]))
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				if (game->map[y][x] == 'N')
					game->player.dir = M_PI / 2;
				else if (game->map[y][x] == 'S')
					game->player.dir = 3 * M_PI / 2;
				else if (game->map[y][x] == 'E')
					game->player.dir = 0;
				else if (game->map[y][x] == 'W')
					game->player.dir = M_PI;
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	handle_key(int keycode, t_game *game)
{
	double new_x;
	double new_y;

	if (keycode == ESC_KEY)
	{
		cleanup_game(game);
		exit(0);
	}
	if (keycode == KEY_W)
	{
		new_x = game->player.x + cos(game->player.dir) * MOVE_SPEED;
		new_y = game->player.y + sin(game->player.dir) * MOVE_SPEED;
		if (game->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	else if (keycode == KEY_S)
	{
		new_x = game->player.x - cos(game->player.dir) * MOVE_SPEED;
		new_y = game->player.y - sin(game->player.dir) * MOVE_SPEED;
		if (game->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	else if (keycode == KEY_A)
	{
		new_x = game->player.x - sin(game->player.dir) * MOVE_SPEED;
		new_y = game->player.y + cos(game->player.dir) * MOVE_SPEED;
		if (game->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	else if (keycode == KEY_D)
	{
		new_x = game->player.x + sin(game->player.dir) * MOVE_SPEED;
		new_y = game->player.y - cos(game->player.dir) * MOVE_SPEED;
		if (game->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	else if (keycode == KEY_LEFT)
	{
		game->player.dir -= ROT_SPEED;
		if (game->player.dir < 0)
			game->player.dir += 2 * M_PI;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player.dir += ROT_SPEED;
		if (game->player.dir >= 2 * M_PI)
			game->player.dir -= 2 * M_PI;
	}
	return (0);
}