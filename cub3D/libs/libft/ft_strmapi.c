/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:27:39 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:51:14 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*newstr;
	int					len;
	unsigned int		i;

	i = 0;
	len = ft_strlen(s);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!s || !newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
char	myfunc(unsigned int i, char str)
{
	(void)i;
	str = str - 32;
	return (str);
}

int	main(void)
{
	char *str = "yellow";
	printf("The initial string is %s\n", str);
	char *result = ft_strmapi(str, myfunc);
	printf("The new string is %s\n", result);
	return (0);
}
*/
