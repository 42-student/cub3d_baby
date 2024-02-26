/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:27:24 by smargine          #+#    #+#             */
/*   Updated: 2023/09/26 17:32:32 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	char	*s;
	int		len;
	double	a;
	double	b;

	s = (char *)str;
	a = (double)ft_atoi(s);
	while (*s && *s != '.')
		s++;
	if (*s == '.')
		s++;
	b = (double)ft_atoi(s);
	len = ft_strlen(s);
	while (len--)
		b = b / 10;
	if (a >= 0)
	{
		if (str[0] == '-')
			return (-(a + b));
		else
			return (a + b);
	}
	else
		return (a + -b);
}
