/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:27:18 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:27:20 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <fcntl.h>
int	main(void) {
	int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd < 0) {
		return (1);
	}

	ft_putchar_fd('A', file_fd);
	ft_putchar_fd('B', file_fd);
	ft_putchar_fd('C', file_fd);
	ft_putchar_fd('D', file_fd);
	ft_putchar_fd('\n', file_fd);

	close(file_fd);

	return (0);
}*/
