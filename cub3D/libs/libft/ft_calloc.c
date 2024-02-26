/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:27:30 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 11:34:02 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	totalsize;
	char	*p;
	size_t	i;

	totalsize = nelem * elsize;
	ptr = malloc(totalsize);
	p = ptr;
	i = 0;
	while (ptr != 0 && i < totalsize)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	int	*a;
	int	n;
	int	i;

	i = 0;
	printf("Number of elements to be entered: ");
	scanf("%d", &n);
	a = (int *)ft_calloc(n, sizeof(int));
	printf("Enter %d numbers:\n", n);
	while (i < n)
	{
		scanf("%d", &a[i]);
		i++;
	}
	printf("The numbers entered are: ");
	i = 0;
	while (i < n)
	{
		printf("%d ", a[i]);
		i++;
	}
	free (a);
	return (0);
}
*/
