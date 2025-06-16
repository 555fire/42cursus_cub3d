/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:08:20 by lchuang           #+#    #+#             */
/*   Updated: 2025/06/16 11:13:38 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define TITLE "cub3d test window"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
	if (!win)
		return (1);
	mlx_loop(mlx);
	return (0);
}
