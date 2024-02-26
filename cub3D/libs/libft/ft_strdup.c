/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:48:40 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:28:18 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	newstr = malloc(sizeof(char) * i + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
int	main(void)
{
	char	*s;
	char	*s1;

	s = ft_strdup("lol");
	printf("%s\n", s);
	s1 = strdup("lol");
	printf("%s\n", s1);
	return (0);
}
*/
