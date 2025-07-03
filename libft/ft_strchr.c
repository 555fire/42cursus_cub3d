/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:28:32 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:28:44 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = c % 128;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

/*#include <stdio.h>
int	main(void) {
	const char *str = "Hello, world!";
	char ch = 'o';
	char *result;

	result = ft_strchr(str, ch);
	if (result != NULL)
		printf(" '%c' at %ld\n", ch, result - str);
	else
		printf("error!\n");

	return (0);
}*/