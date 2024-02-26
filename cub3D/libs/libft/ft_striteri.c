/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:49 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:29:40 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	myfunc(unsigned int i, char *s)
{	
	if (i == 2 || i == 3)
		s[0] = 'X';
}

int	main(void)
{
	char str[6] = "yoyoma";
	printf("The initial string is: %s\n", str);
	ft_striteri(str, myfunc);
	printf("The new string is: %s\n", str);
	return (0);
}
*/
