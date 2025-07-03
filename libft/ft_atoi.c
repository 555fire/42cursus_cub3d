/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:57:53 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 11:57:54 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

/*#include <stdio.h>
int	main(void) {

	char *test1 = "42";
	char *test2 = "   -42";
	char *test3 = "   +42";
	char *test4 = "4193 AAAA";
	char *test5 = "words and 987";
	char *test6 = "-91283472332";
	char *test7 = "  123  456";

	printf("(\"%s\") = %d\n", test1, ft_atoi(test1));
	printf("(\"%s\") = %d\n", test2, ft_atoi(test2));
	printf("(\"%s\") = %d\n", test3, ft_atoi(test3));
	printf("(\"%s\") = %d\n", test4, ft_atoi(test4));
	printf("(\"%s\") = %d\n", test5, ft_atoi(test5));
	printf("(\"%s\") = %d\n", test6, ft_atoi(test6));
	printf("(\"%s\") = %d\n", test7, ft_atoi(test7));

	return (0);
}*/
