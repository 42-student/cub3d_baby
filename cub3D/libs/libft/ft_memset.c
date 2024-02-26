/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:39:26 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:12:27 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[100] = "yes ohh yes";
	char	str1[100] = "yes ohh yes";

	printf("%s\n", (char *)ft_memset(str + 4, 48, 4));
	printf("%s\n", (char *)memset(str1 + 4, 48, 4));
	return (0);
}
*/
