/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:50:37 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/05 15:52:06 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "map.h"
# include "mlx.h"
# include "raycast.h"
# include "structs.h"
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

# define ESC_KEY 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65363
# define KEY_RIGHT 65361
// # define ESC_KEY 53
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_LEFT 123
// # define KEY_RIGHT 124

# define MOVE_SPEED 1
# define ROT_SPEED 0.1

# define MAX_INFINITY 1e30
# define MIN_INFINITY 0.05

void	init_player(t_game *game);
void	cleanup_game(t_game *game);
int		handle_key(int keycode, t_game *game);
int		handle_close(t_game *game);

#endif