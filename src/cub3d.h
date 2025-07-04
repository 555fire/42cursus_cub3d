/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:50:37 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/04 11:17:46 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "raycast/raycast.h"
# include "map/map.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 640
# define HEIGHT 480
# define TITLE "cub3d test window"
# define MAX_LINE 1024

# define ESC_KEY 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define MOVE_SPEED 0.5
# define ROT_SPEED 0.1

# define TILE_SIZE 10
# define FOV (M_PI / 3)

void			init_player(t_game *game);
void			cleanup_game(t_game *game);
int				handle_key(int keycode, t_game *game);
int				handle_close(t_game *game);

#endif