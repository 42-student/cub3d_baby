/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:32:54 by smargine          #+#    #+#             */
/*   Updated: 2023/09/06 14:13:47 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*s != '\0')
	{
		if (*s != c && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static void	ft_free(char **result, int j)
{
	while (j--)
		free(result[j]);
	free(result);
}

static int	ft_sizeword(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!result)
		return (NULL);
	while (j < ft_countwords(s, c))
	{
		while (s[i] == c)
			i++;
		result[j] = ft_substr(s, i, ft_sizeword(s, c, i));
		if (!result[j])
		{
			ft_free(result, j);
			return (NULL);
		}
		i = i + ft_sizeword(s, c, i);
		j++;
	}
	result[j] = NULL;
	return (result);
}
/*
int	main(void)
{
	char	*s;
	char	**split_strings;
	int		i;

	i = 0;
	s = "To be or not to be";
	split_strings = ft_split(s, ' ');
	while (i < 7)
	{
		printf("%s\n", split_strings[i]);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		free(split_strings[i]);
		i++;
	}
	free(split_strings);
	return (0);
}
*/
