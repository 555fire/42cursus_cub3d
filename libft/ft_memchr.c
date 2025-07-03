/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:00:30 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:00:31 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	const char str[] = "Hello, world!";
	int ch = 'o';
	size_t n = 13;

	char *result = ft_memchr(str, ch, n);

	if (result != NULL)
		printf("'%c' at position: %ld\n", ch, result - str);
	else
		printf("'%c' not found\n", ch);

	return (0);
}*/