/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:23:40 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:52:48 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = 0;
	y = 0;
	x = 0;
	while (little[x])
		x++;
	if (x == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while ((big[i + y] == little[y]) && ((i + y) < len))
		{
			if (y == x - 1)
				return ((char *)big + i);
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strnstr("", "cd", 4294967295));
	return (0);
}
*/
