/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:13:02 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:11:15 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if (!d && !s)
		return (0);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;
	char		*temp;

	d = dest;
	s = src;
	i = 0;
	temp = malloc(sizeof(char) * n);
	if (temp == NULL)
		return (NULL);
	while (i < n)
	{
		*(temp + i) = *(s + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*(d + i) = *(temp + i);
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	s[20] = "Berlin42!";
	char	s1[20] = "Berlin42!";

	ft_memmove(s + 3, s, 6);
	printf("%s\n", s);
	memmove(s1 + 3, s1, 6);
	printf("%s\n", s1);
	return (0);
}
*/
