/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:30:12 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:30:14 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup((const char *)""));
	else if (!f)
		return (ft_strdup((const char *)s));
	rtn = ft_strdup((const char *)s);
	if (!rtn)
		return (rtn = NULL);
	while (s[i])
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	return (rtn);
}

/*#include <stdio.h>
char	func(unsigned int i, char c) {
	return (c+1);
}
int	main(void) {
	const char *str = "aaaaaaa";
	char *result;

	result = ft_strmapi(str, func);
	if (result) {
		printf("Original: %s\n", str);
		printf("Modified: %s\n", result);
		free(result);
	} else {
		printf("error!\n");
	}

	return (0);
}*/