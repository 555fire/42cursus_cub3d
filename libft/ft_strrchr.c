/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:30:48 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:30:49 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	c = c % 128;
	len = ft_strlen(s);
	s = s + len;
	while (len + 1)
	{
		if (*s == c)
			return ((char *)s);
		len--;
		s--;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	const char	*str = "ABCDEFG";
	int			ch1;
	int			ch2;

	ch1 = 'D';
	ch2 = '\0';
	printf("'%c' in '%s': %s\n", ch1, str, ft_strrchr(str, ch1));
	printf("'%c' in '%s': %s\n", ch2, str, ft_strrchr(str, ch2));
	return (0);
}*/
