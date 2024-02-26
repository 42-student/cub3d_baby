/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:02:36 by smargine          #+#    #+#             */
/*   Updated: 2023/09/09 13:37:08 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen_gnl(s1) \
		+ ft_strlen_gnl(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		new_str[i + y] = s2[y];
		y++;
	}
	new_str[i + y] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr_gnl(char *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen_gnl(str))
		return (NULL);
	if (ft_strlen_gnl(str + start) < len)
		len = ft_strlen_gnl(str + start);
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (i < len && str[i])
	{
		sub_str[i] = str[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
