/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:28:24 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 12:28:25 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	counter;

	str = (char *)s;
	if (str && f)
	{
		counter = 0;
		while (str[counter])
		{
			(*f)(counter, &str[counter]);
			counter++;
		}
	}
}

/*#include <stdio.h>
void	func(unsigned int i, char *c) {
	*c = *c + 1;
}

int	main(void) {
	char str[] = "abcdefg";
	ft_striteri(str, func);
	printf("Modified: %s\n", str);

	return (0);
}*/