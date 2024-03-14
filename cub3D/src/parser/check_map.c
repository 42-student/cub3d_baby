/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastian <sebastian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:23:34 by smargine          #+#    #+#             */
/*   Updated: 2024/03/14 19:25:51 by sebastian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Checks the map size and updates the map width and height,
 * in the structure.
*/
int	ft_check_map(char *file, t_pars *pars)
{
	char	*line;
	int		fd;
	int		start;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!start)
			start = ft_check_line(line);
		if (start && !ft_check_line(line))
		{
			free(line);
			ft_go_to_end(fd);
			close(fd);
			return (0);
		}
		if (start)
			pars->map_height++;
		if (start && ft_line_lenght(line) > pars->map_width)
			pars->map_width = ft_line_lenght(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}


/**
 * Goes to the end of file, avoiding reading unnecessary lines.
*/
void	ft_go_to_end(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

/**
 * Calculates the lenght of a line.
*/
int	ft_line_lenght(char *line)
{
	int	i;
	int	len;
	int	valid_char;

	i = 0;
	len = 0;
	valid_char = 0;
	while (line[i])
	{
		if (!ft_valid_char(line[i]) && valid_char)
			len = i;
		valid_char = ft_valid_char(line[i]);
		i++;
	}
	return (len);
}

/**
 * Checks if the character is valid.
*/
int	ft_valid_char(char c)
{
	if (c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

/**
 * Verifying if the map is valid.
*/
int	ft_verify_map(t_pars *pars)
{
	int	start;

	if (ft_invalid_char(pars))
	{
		ft_putendl_fd("Error! Invalid characters.", 2);
		return (1);
	}
	start = ft_starting_point(pars);
	if (start == 0)
	{
		ft_putendl_fd("Error! Map has no starting point.", 2);
		return (1);
	}
	if (start > 1)
	{
		ft_putendl_fd("Error! Map has more than one starting point.", 2);
		return (1);
	}
	if (ft_check_walls(pars))
	{
		ft_putendl_fd("Error! Map is not enclosed by walls.", 2);
		return (1);
	}
	return (0);
}

/**
 * Checks if the map contains invalid characters.
*/
int	ft_invalid_char(t_pars *pars)
{
	int	**temp;
	int	i;

	temp = pars->map;
	while (*temp)
	{
		i = 0;
		while (i < pars->map_width)
		{
			if (temp[0][i] == -1)
				return (1);
			i++;
		}
		temp++;
	}
	return (0);
}

/**
 * Checks the number of starting points.
*/
int	ft_starting_point(t_pars *pars)
{
	int	**temp;
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	temp = pars->map;
	while (temp[i])
	{
		j = 0;
		while (j < pars->map_width)
		{
			if (temp[i][j] >= 3 && temp[i][j] <= 6)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

/**
 * Checks if the map is enclosed by walls.
*/
int	ft_check_walls(t_pars *pars)
{
	int	**temp;
	int	i;
	int	j;

	temp = pars->map;
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (j < pars->map_width)
		{
			if (temp[i][j] == 1 || (temp[i][j] >= 3 && temp[i][j] <= 6))
			{
				if (i <= 0 || j <= 0 || i >= pars->map_height -1 || j >= pars->map_width -1)
					return (1);
				if (!temp[i - 1][j] || !temp[i + 1][j] || !temp[i][j - 1] || !temp[i][j + 1])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
