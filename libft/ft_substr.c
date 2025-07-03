/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:31:09 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:31:17 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen((const char *)s) < start)
	{
		ptr = (char *)malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	if ((unsigned int)ft_strlen((const char *)s) - start > len)
		i = len + 1;
	else
		i = ft_strlen((const char *)s) - start + 2;
	ptr = (char *)malloc((i) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (const char *)(s + start), i);
	return (ptr);
}

/*#include <stdio.h>
int	main(void) {
	char s[] = "0123456789012345";
	char *substr;

	substr = ft_substr(s, 7, 5);
	printf("substr: '%s'\n", substr);
	free(substr);

	return (0);
}*/