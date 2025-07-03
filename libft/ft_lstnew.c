/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:59:55 by lchuang           #+#    #+#             */
/*   Updated: 2024/05/14 11:59:56 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->content = content;
	return (rtn);
}

/*#include <stdio.h>
void	print(void *content) {
	printf("%s\n", (char *)content);
}
void	del(void *content) {
	free(content);
}
int	main(void) {
	// 創建一個空鏈表
	t_list *list = NULL;

	t_list *node1 = ft_lstnew(ft_strdup("data 1"));
	t_list *node2 = ft_lstnew(ft_strdup("data 2"));
	t_list *node3 = ft_lstnew(ft_strdup("data 3"));

	ft_lstadd_front(&list, node2);
	ft_lstiter(list, print);
	printf("\n\n");

	ft_lstadd_front(&list, node1);
	ft_lstiter(list, print);
	printf("\n\n");

	ft_lstadd_back(&list, node3);
	ft_lstiter(list, print);
	printf("\n\n");

	printf("%d\n\n",ft_lstsize(list));

	ft_lstclear(&list, &free);
	if (list == NULL) {
		printf("List cleared!\n");
	} else {
		printf("Error!\n");
	}
	printf("\n");


	return (0);
}*/