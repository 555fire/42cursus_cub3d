/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:58:04 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 11:58:05 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = (void *)malloc(size * count);
	if (rtn == NULL)
		return (NULL);
	ft_bzero(rtn, count * size);
	return (rtn);
}

/*#include <stdio.h>
int	main(void) {
	size_t num_elements = 5;
	size_t element_size = sizeof(int);

	int *array = (int *)ft_calloc(num_elements, element_size);
	if (array == NULL) {
		printf("error!\n");
		return (1);
	}
	printf("values:\n");
	for (size_t i = 0; i < num_elements; ++i) {
		printf("array[%zu] = %d\n", i, array[i]);
	}

	free(array);
	return (0);
}*/