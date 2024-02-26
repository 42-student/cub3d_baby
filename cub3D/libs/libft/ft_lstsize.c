/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:06:08 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:00:46 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	head = (t_list *)malloc(sizeof(t_list));
	list1 = (t_list *)malloc(sizeof(t_list));
	list2 = (t_list *)malloc(sizeof(t_list));
	list3 = (t_list *)malloc(sizeof(t_list));
	head->next = list1;
	list1->next = list2;
	list2->next = list3;
	list3 = NULL;
	printf("%d\n", ft_lstsize(head));
	return (0);
}
*/
