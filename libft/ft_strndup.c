/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurose <kkurose@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:58:09 by kkurose           #+#    #+#             */
/*   Updated: 2025/05/16 20:59:00 by kkurose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	ft_memcpy(rtn, s1, len);
	rtn[len] = '\0';
	return (rtn);
}
