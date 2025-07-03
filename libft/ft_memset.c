/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:31:11 by lchuang           #+#    #+#             */
/*   Updated: 2024/04/19 17:34:42 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)b;
	while (len > 0)
	{
		*(ptr) = c;
		ptr++;
		len--;
	}
	return (b);
}

/*#include <stdio.h>
int	main(void)
{
	int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	ft_memset(num, 0, 5 * sizeof(int));
	printf("new num: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	return (0);
}*/