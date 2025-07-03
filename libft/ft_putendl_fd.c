/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:27:29 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:27:30 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

/*#include <fcntl.h>
int	main(void) {
	int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd < 0) {
		return (1);
	}
	ft_putendl_fd("YYY", file_fd);
	close(file_fd);

	return (0);
}*/