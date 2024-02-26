/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:37:57 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 11:54:53 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return (current);
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
/*
int	main(void)
{
	char	*str;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*res;

	str = "Kramer from Seinfeld :)";
	list1 = (t_list *)malloc(sizeof(t_list));
	list2 = (t_list *)malloc(sizeof(t_list));
	list3 = (t_list *)malloc(sizeof(t_list));
	list1->next = list2;
	list2->next = list3;
	list3->next = NULL;
	list3->content = (void *)str;
	res = ft_lstlast(list1);
	printf("%s\n", (char *)res->content);
	return (0);
}
*/
