/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:00:53 by lchuang           #+#    #+#             */
/*   Updated: 2025/07/14 11:09:30 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "structs.h"

int		render(t_game *game);
void	draw_column(t_game *game, int x);
t_ray	setup_ray(t_game *g, int x);
int		perform_dda(t_game *g, t_ray *r);
void	calc_line_params(t_game *g, t_ray *r, int side, t_column_params *p);
void	calc_texture_params(t_game *g, t_ray *r, int side, t_column_params *p);

#endif