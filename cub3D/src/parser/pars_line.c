/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastian <sebastian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:15:13 by smargine          #+#    #+#             */
/*   Updated: 2024/02/26 20:40:35 by sebastian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Parsing a line. Extract data from a line,
 * handling texture and color.
*/
int	ft_pars_line(char *file, t_pars *pars)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strtrim(line, " \n");
		if (!temp)
		{
			close(fd);
			return (1);
		}
		if (ft_store_data_line(temp, pars))
		{
			close(fd);
			return (1);
		}
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	if (ft_check_mandatory_data(pars))
	{
		ft_putendl_fd("Error! Mandatory data is missing.", 2);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

/**
 * Store data extracted from a line.
*/
int	ft_store_data_line(char *line, t_pars *pars)
{
	char	**temp;

	if (ft_check_identical_data(line, pars))
	{
		ft_putendl_fd("Error! Identical data line.", 2);
		return (1);
	}
	temp = ft_split(line, ' ');
	if (!temp)
		return (1);
	if (!temp[0] || !temp[1])
	{
		ft_free_2d_arr(temp);
		return (0);
	}
	if (ft_check_texture(line))
		if (ft_store_texture_line(temp, pars))
		{
			ft_free_2d_arr(temp);
			return (1);
		}
	if (ft_check_color(line))
	{
		if (ft_store_color_line(temp, pars))
		{
			ft_free_2d_arr(temp);
			return (1);
		}
	}
	ft_free_2d_arr(temp);
	return (0);
}


/**
 * Store texture from a line in the pars structure.
*/
int	ft_store_texture_line(char **line, t_pars *pars)
{
	if (!ft_strncmp(line[0], "NO ", 2))
		pars->no = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "SO ", 2))
		pars->so = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "WE ", 2))
		pars->we = ft_strdup(line[1]);
	if (!ft_strncmp(line[0], "EA ", 2))
		pars->ea = ft_strdup(line[1]);
	if (line[2])
	{
		ft_putendl_fd("Error! Invalid characters after data line.", 2);
		return (1);
	}
	return (0);
}

/**
 * Store color from a line in the pars structure.
*/
int	ft_store_color_line(char **line, t_pars *pars)
{
	char	**color;

	color = ft_split(line[1], ',');
	if (!color)
		return (1);
	if (!color[0] || !color[1] || !color[2] || color[3] \
		|| ft_validate_color(color))
	{
		ft_free_2d_arr(color);
		ft_putendl_fd("Error! Wrong color format.", 2);
		return (1);
	}
	if (!ft_strncmp(line[0], "F", 1))
	{
		pars->f_color = (ft_atoi(color[0]) << 16) + \
			(ft_atoi(color[1]) << 8) + (ft_atoi(color[2]));
		pars->f_flag = 1;
	}
	if (!ft_strncmp(line[0], "C", 1))
	{
		pars->c_color = (ft_atoi(color[0]) << 16) + \
			(ft_atoi(color[1]) << 8) + (ft_atoi(color[2]));
		pars->c_flag = 1;
	}
	if (line[2])
	{
		ft_free_2d_arr(color);
		ft_putendl_fd("Error! Invalid characters after data line.", 2);
		return (1);
	}
	ft_free_2d_arr(color);
	return (0);
}

/**
 * Validate the color.
*/
int	ft_validate_color(char **color)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		temp = color[i];
		j = -1;
		while (temp[++j])
			if (!ft_isdigit(temp[j]))
				return (1);
		i = ft_atoi(temp);
		if (i < 0 || i > 255)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Checks if mandatory data is present in the file.
*/
int	ft_check_mandatory_data(t_pars *pars)
{
	if (!(pars->no && pars->so && pars->we && pars->ea))
		return (1);
	if (!(pars->c_flag && pars->f_flag))
		return (1);
	return (0);
}

/**
 * Checks if a line is identical to the previous parsed data.
*/
int	ft_check_identical_data(char *line, t_pars *pars)
{
	if (!ft_strncmp(line, "NO ", 3) && pars->no)
		return (1);
	if (!ft_strncmp(line, "SO ", 3) && pars->so)
		return (1);
	if (!ft_strncmp(line, "WE ", 3) && pars->we)
		return (1);
	if (!ft_strncmp(line, "EA ", 3) && pars->ea)
		return (1);
	if (!ft_strncmp(line, "F ", 2) && pars->f_flag)
		return (1);
	if (!ft_strncmp(line, "C ", 2) && pars->c_flag)
		return (1);
	return (0);
}
