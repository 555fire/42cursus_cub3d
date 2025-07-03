/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:01 by lchuang           #+#    #+#             */
/*   Updated: 2024/04/22 15:18:03 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

/*#include <stdio.h>
int	main(void)
{
	char src[] = "Hello, world!";
	char dst[50];

	// 使用自定義的 ft_memcpy 函數來複製 src 到 dst
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	printf("dst: %s\n", dst);

	return (0);
}*/