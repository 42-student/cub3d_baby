/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:25 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:34:36 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (dst[i])
		i++;
	while (src[len])
		len++;
	if (size <= i)
		return (size + len);
	else
	{
		while (src[j] && j < (size - i - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	return (i + len);
}
/*
int	main(void)
{
	char	d[] = "aaabbb";
	char	s[] = "cccdddxxx";
	char	d1[] = "aaabbb";
	char	s1[] = "cccdddxxx";
	size_t	a;
	size_t	b;

	a = ft_strlcat(d, s, 7);
	b = strlcat(d1, s1, 7);
	printf("%lu\n", a);
	printf("%lu\n", b);
	return (0);
}
*/
