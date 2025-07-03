/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:30:22 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:30:30 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	int		diff;

	count = 1;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && count++ < n)
	{
		s1++;
		s2++;
	}
	diff = ((unsigned char)*s1 - (unsigned char)*s2);
	return (diff);
}

/*#include <stdio.h>
int	main(void) {
	const char *str1 = "AAAAAAA";
	const char *str2 = "AAAAAAA";
	const char *str3 = "AAAAAAa";
	const char *str4 = "AAAAA";

	printf("str1 and str2: %d\n", ft_strncmp(str1, str2, 5)); //output: 0
	printf("str1 and str3: %d\n", ft_strncmp(str1, str3, 13)); //output: <0
	printf("str1 and str4: %d\n", ft_strncmp(str1, str4, 5)); //output: 0
	printf("str1 and str4: %d\n", ft_strncmp(str1, str4, 10)); //output: >0

	return (0);
}*/