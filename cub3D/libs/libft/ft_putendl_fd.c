/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:55:18 by smargine          #+#    #+#             */
/*   Updated: 2023/05/24 12:20:10 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, &*s++, 1);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	ft_putendl_fd("Cluj-Napoca", 1);
	return (0);
}
*/
