/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastian <sebastian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:17 by smargine          #+#    #+#             */
/*   Updated: 2024/03/14 19:24:09 by sebastian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_memset(&data, 0, sizeof(t_data));
		if (ft_parsing(av[1], &data.pars))
			return (1); // I need a free function here!!! meow ^_^
	}
	else
		ft_putendl_fd("Error! Invalid number of arguments.", 2);
	return (0);
}

/**
 * Parses a file, extracts relevant data, populates the structure.
*/
int	ft_parsing(char *file, t_pars *pars)
{
	ft_memset(pars, 0, sizeof(t_pars));
	if (ft_check_extension(file))
	{
		ft_putendl_fd("Error! Invalid file/extension.", 2);
		return (1);
	}
	if (ft_check_file(file))
		return (1);
	if (ft_pars_line(file, pars))
		return (1);
	if (ft_check_map(file, pars))
		return (1);
	if (ft_alloc_map(pars))
		return (1);
	if (ft_map_init(file, pars))
		return (1);
	if (ft_verify_map(pars))
		return (1);
	return (0);
}
