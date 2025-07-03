/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:30:59 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:31:02 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((const char *)s1));
	start = 0;
	end = (size_t)ft_strlen((const char *)s1);
	while (is_in_set(s1[start], set) == 0)
		start++;
	if (start == (size_t)ft_strlen((const char *)s1))
	{
		rtn = ft_strdup((const char *)"");
		if (!(rtn))
			return (NULL);
		else
			return (rtn);
	}
	while (is_in_set(s1[end - 1], set) == 0)
		end--;
	rtn = ft_substr((char const *)s1, start, end - start);
	return (rtn);
}

/*#include <stdio.h>
int	main(void) {
	char s1[] = "BBAB1234567890BCBB";
	char set[] = "ABC";
	char *trimmed = ft_strtrim(s1, set);

	printf("str: '%s'\n", s1);
	printf("new: '%s'\n", trimmed);

	free(trimmed);
	return (0);
}*/