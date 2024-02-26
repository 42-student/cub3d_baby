/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:49:57 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:51:58 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	*s;
	char	*s1;
	char	*s2;
	char	*s3;
	int		a;
	int		b;

	s = "ba";
	s1 = "babg";
	s2 = "ba";
	s3 = "babg";
	a = ft_strncmp(s, s3, 2);
	b = strncmp(s1, s2, 2);
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);	
}
*/
