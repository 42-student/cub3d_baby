/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:42:52 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:31:00 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	int		len;
	char	*newstr;

	i = 0;
	y = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		newstr[i + y] = s2[y];
		y++;
	}
	newstr[i + y] = '\0';
	return (newstr);
}
/*
int	main(void)
{
	char	*a;

	a = ft_strjoin("Ber", "lin");
	printf("%s\n", a);
	return (0);
}
*/
