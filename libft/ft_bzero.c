/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:06:24 by lchuang           #+#    #+#             */
/*   Updated: 2024/04/22 15:06:26 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*#include <stdio.h>
#include <string.h>

int	main(void) {
	char buffer[10];
	strcpy(buffer, "abcdef");
	printf("Before: %s\n", buffer);

	ft_bzero(buffer, 4);

	printf("After: ");
	for (int i = 0; i < 10; i++) {
		if (buffer[i] == '\0')
			printf("\\0");
		else
			printf("%c", buffer[i]);
	}
	printf("\n");

	return (0);
}*/