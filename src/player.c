/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:27:58 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 15:04:58 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	place_player(t_game *game, int x, int y, char c)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (c == 'N')
		game->player.dir = 3 * M_PI / 2;
	else if (c == 'S')
		game->player.dir = M_PI / 2;
	else if (c == 'E')
		game->player.dir = 0;
	else if (c == 'W')
		game->player.dir = M_PI;
	game->map[y][x] = '0';
}

void	init_player(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			c = game->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				place_player(game, x, y, c);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	try_move(t_game *game, double new_x, double new_y)
{
	if (game->map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

static void	process_movement(int keycode, t_game *game)
{
	double	dir;
	double	new_x;
	double	new_y;
	double	factor;

	dir = game->player.dir;
	factor = -1;
	if (keycode == KEY_W || keycode == KEY_S)
	{
		if (keycode == KEY_W)
			factor = 1;
		new_x = game->player.x + cos(dir) * MOVE_SPEED * factor;
		new_y = game->player.y + sin(dir) * MOVE_SPEED * factor;
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_D)
			factor = 1;
		new_x = game->player.x + sin(dir) * MOVE_SPEED * factor;
		new_y = game->player.y - cos(dir) * MOVE_SPEED * factor;
	}
	else
		return ;
	try_move(game, new_x, new_y);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		cleanup_game(game);
		put_endmsg();
		exit(0);
	}
	process_movement(keycode, game);
	if (keycode == KEY_RIGHT)
		game->player.dir -= ROT_SPEED;
	else if (keycode == KEY_LEFT)
		game->player.dir += ROT_SPEED;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (game->player.dir < 0)
			game->player.dir += 2 * M_PI;
		else if (game->player.dir >= 2 * M_PI)
			game->player.dir -= 2 * M_PI;
	}
	return (0);
}
