/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastian <sebastian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:12:15 by smargine          #+#    #+#             */
/*   Updated: 2024/03/14 19:18:43 by sebastian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Allocates memory for the map.
*/
int	ft_alloc_map(t_pars *pars)
{
	int	i;

	i = 0;
	pars->map = malloc(sizeof(int *) * (pars->map_height + 1));
	if (!pars->map)
		return (1);
	while (i < pars->map_height)
	{
		pars->map[i] = malloc(sizeof(int) * pars->map_width);
		if (!(pars->map[i]))
		{
			ft_free_2d_int(pars->map);
			return (1);
		}
		ft_memset((void *)pars->map[i], 0, sizeof(int) * pars->map_width);
		i++;
	}
	pars->map[i] = 0;
	return (0);
}

/**
 * Reads the map from a file and fills the map in the structure.
*/
int	ft_map_init(char *file, t_pars *pars)
{
	char	*line;
	int		i;
	int		fd;
	int		start;

	i = 0;
	start = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (!start)
			start = ft_check_line(line);
		if (start && !ft_check_line(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		if (start)
		{
			ft_fill_map(line, pars->map[i]);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/**
 * Fills the array map in the structure.
*/
void	ft_fill_map(char *line, int *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			map[i] = 0;
		else if (line[i] == '0')
			map[i] = 1;
		else if (line[i] == '1')
			map[i] = 2;
		else if (line[i] == 'N')
			map[i] = 3;
		else if (line[i] == 'S')
			map[i] = 4;
		else if (line[i] == 'E')
			map[i] = 5;
		else if (line[i] == 'W')
			map[i] = 6;
		else
			map[i] = -1;
		i++;
	}
}
