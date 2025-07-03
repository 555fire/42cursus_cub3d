/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:29:44 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:29:45 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen((const char *)src));
}

/*#include <stdio.h>
int	main(void) {
	char dest[20] = "AAA";
	const char *src = "BBBB";
	size_t size = 15;
	size_t result;

	result = ft_strlcat(dest, src, size);
	printf("result: %zu\n", result);
	printf("dest: %s\n", dest);

	return (0);
}*/