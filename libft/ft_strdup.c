/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:28:56 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:28:58 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen((const char *)s1) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (0);
	rtn = ft_memcpy(rtn, s1, len);
	return (rtn);
}

/*#include <stdio.h>
int	main(void) {
	const char *str = "Hello, world!";
	char *dup_str;

	dup_str = ft_strdup(str);
	if (dup_str != NULL) {
		printf("dup_str: %s\n", dup_str);
		free(dup_str);
	} else {
		printf("error!\n");
	}

	return (0);
}*/