/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:29:55 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:29:56 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (src[c] != '\0')
		c++;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (c);
}

/*#include <stdio.h>
int	main(void) {
	char dest[20];
	const char *src = "YYYZZZZ";
	size_t size = sizeof(dest);
	size_t result;

	result = ft_strlcpy(dest, src, size);
	printf("result: %zu\n", result);
	printf("dest: %s\n", dest);

	return (0);
}*/