/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:53:41 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 11:32:20 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str[100] = "Berlin is the place to be...";
	char	str1[100] = "Berlin is the place to be...";

	ft_bzero(str + 6, 4);
	printf("%s\n", str);
	bzero(str1 + 6, 4);
	printf("%s\n", str1);
	return (0);
}
*/
