/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:13:19 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:13:20 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	i = 0;
	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

/*#include "stdio.h"
int	main(void)
{
	char str1[] = "AAAAA";
	char str2[] = "BBBBB";
	char str3[] = "AAAAA";
	size_t n1 = 5;
	size_t n2 = 5;

	// str1 和 str2
	int result1 = ft_memcmp(str1, str2, n1);
	if (result1 < 0)
		printf("'%s' < '%s'\n", str1, str2);
	else if (result1 > 0)
		printf("'%s' > '%s'\n", str1, str2);
	else
		printf("'%s' = '%s'\n", str1, str2);

	// str1 和 str3
	int result2 = ft_memcmp(str1, str3, n2);
	if (result2 < 0)
		printf("'%s' < '%s'\n", str1, str3);
	else if (result2 > 0)
		printf("'%s' > '%s'\n", str1, str3);
	else
		printf("'%s' = '%s'\n", str1, str3);

	return (0);
}*/
