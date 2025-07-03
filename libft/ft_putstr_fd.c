/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:27:59 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:28:01 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
}

/*#include <fcntl.h>
int	main(void) {
	int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd < 0) {
		return (1);
	}
	ft_putstr_fd("UUU", file_fd);
	close(file_fd);

	return (0);
}*/