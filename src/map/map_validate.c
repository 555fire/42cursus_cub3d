/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:12:03 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 07:31:50 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	validate_map_cell(t_game *game, int y, int x, int *player_cnt)
{
	char	c;

	c = game->map[y][x];
	if (c == ' ')
		return (1);
	if (c == '0' || ft_strchr("NSEW", c))
	{
		if (y == 0 || y == game->map_height - 1 || x == 0
			|| x == game->map_width - 1)
			return (put_errmsg("Not enclosed by walls"));
		if (game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' '
			|| game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' ')
			return (put_errmsg("Invalid open space"));
		if (ft_strchr("NSEW", c))
			(*player_cnt)++;
	}
	else if (c != '1')
		return (put_errmsg("Invalid character"));
	return (1);
}

static int	validate_map_body(t_game *game, int *player_cnt)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (!validate_map_cell(game, y, x, player_cnt))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int	player_cnt;

	player_cnt = 0;
	if (!validate_map_body(game, &player_cnt))
		return (0);
	if (player_cnt != 1)
		return (put_errmsg("Exactly 1 player is required"), 0);
		// return (put_errmsg("Exactly 1 player is required"));
	return (1);
}
