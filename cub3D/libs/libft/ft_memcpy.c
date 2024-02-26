/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 07:39:18 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:09:05 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "xxx";
	char	dest[] = "This is Sparta!";
	char	src1[] = "xxx";
	char	dest1[] = "This is Sparta!";

	ft_memcpy(dest, src, 2);
	printf("%s\n", dest);
	memcpy(dest1, src1, 2);
	printf("%s\n", dest1);
	return (0);
}

int	main(void)
{
	//char	s[10] = "Berlin";
	//char	s1[10] = "Berlin";

	char *s = ft_memcpy(((void*)0), ((void*)0), 3);
	printf("%s\n", s);
	//memcpy(((void*)0), ((void*)0), 3);
	//printf("%s\n", s1);
	return (0);
}
*/
