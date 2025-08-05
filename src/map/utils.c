/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:10:12 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/05 16:04:13 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_split(char **parts)
{
	int	i;

	i = 0;
	while (parts && parts[i])
		free(parts[i++]);
	free(parts);
}

int	rpg_to_bit(char *str)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(str, ',');
	if (!parts)
		return (-1);
	if (!parts[0] || !parts[1] || !parts[2] || parts[3])
		return (free_split(parts), -1);
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_split(parts), -1);
	free_split(parts);
	return ((r << 16) | (g << 8) | b);
}

int	put_stderr(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

// int	put_stderr(char *msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	ft_putstr_fd("\n", 2);
// 	return (0);
// }
