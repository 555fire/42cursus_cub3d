/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:12:03 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 08:34:50 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	validate_map_cell(t_game *game, int y, int x, int *player_cnt)
{
	char	cell;

	cell = game->map[y][x];
	if (ft_strchr("NSWE", cell))
		(*player_cnt)++;
	if (ft_strchr("0NSWE", cell))
	{
		if (y == 0 || y == game->map_height - 1 || x == 0
			|| x >= (int)ft_strlen(game->map[y - 1])
			|| x >= (int)ft_strlen(game->map[y + 1])
			|| game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' '
			|| game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' ')
			return (put_errmsg("Map must be enclosed by walls"));
	}
	else if (cell != '1' && cell != ' ')
		return (put_errmsg("Invalid character in map"));
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
		while (game->map[y][x])
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
