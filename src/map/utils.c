/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:10:12 by lchuang           #+#    #+#             */
/*   Updated: 2025/08/06 00:13:06 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#define ANSI_BOLD_RED "\033[1;31m"
#define ANSI_ITALIC_RED "\033[3;31m"
#define ANSI_ITALIC_CYAN "\033[3;36m"
#define ANSI_RESET "\033[m"

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

// int	put_stderr(char *msg)
// {
// 	ft_putstr_fd(msg, 2);
// 	ft_putstr_fd("\n", 2);
// 	return (0);
// }

int	put_errmsg(char *msg)
{
	ft_putstr_fd(ANSI_BOLD_RED "Error\n :" ANSI_RESET ANSI_ITALIC_RED, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET "\n\n", STDERR_FILENO);
	return (0);
}

int	put_endmsg(void)
{
	ft_putstr_fd(ANSI_ITALIC_CYAN "Thank you for playing!" ANSI_RESET "\n\n", STDOUT_FILENO);
	return (0);
}
