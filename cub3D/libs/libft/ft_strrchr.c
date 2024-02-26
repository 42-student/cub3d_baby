/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:03:58 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:53:49 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;

	new = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			new = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else
		return (new);
}
/*
int	main(void)
{
	printf("%s\n", ft_strrchr("Berlllin", 'Z'));
	return (0);
}
*/
