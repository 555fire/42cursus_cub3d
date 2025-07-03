/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:29:16 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:29:17 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (ft_strdup((const char *)""));
	if (s1 && !s2)
		return (ft_strdup((const char *)s1));
	if (!s1 && s2)
		return (ft_strdup((const char *)s2));
	s1_len = ft_strlen((const char *)s1);
	s2_len = ft_strlen((const char *)s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	return (rtn);
}

/*#include <stdio.h>
int	main(void) {
	char *str1 = "AAA";
	char *str2 = "BBB";
	char *result;

	result = ft_strjoin(str1, str2);
	printf("%s\n", result);
	free(result);

	return (0);
}*/