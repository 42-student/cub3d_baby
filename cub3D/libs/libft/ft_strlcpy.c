/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:49:27 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:49:47 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && --size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (src[i] && size--)
		{
			dst[i] = src[i];
			i++;
		}
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	d[10] = "cccvvvxxx";
	char	d1[10] = "cccvvvxxx";
	char	*s;
	char	*s1;
	size_t	a;
	size_t	b;

	s = "aaabbbccc";
	s1 = "aaabbbccc";
	a = ft_strlcpy(d, s, 6);
	b = strlcpy(d1, s1, 6);
	printf("%lu\n", a);
	printf("%lu\n", b);
	return (0);
}
*/
