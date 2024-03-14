/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastian <sebastian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:17 by smargine          #+#    #+#             */
/*   Updated: 2024/03/14 19:15:33 by sebastian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Checks if the filename has the ".cub" extension.
*/
int	ft_check_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (1);
	if (file[i - 1] != 'b' || file[i - 2] != 'u' 
		|| file[i - 3] != 'c' || file[i - 4] != '.')
		return (1);
	return (0);
}

/**
 * Checks if the file contains valid data lines, proper 
 * start and end of the map and empty lines after the map.
*/
int	ft_check_file(char *file)
{
	char	*line;
	int		fd;
	int		start;
	int		end;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error! Can't open file.", 2);
		return (1);
	}
	start = 0;
	end = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!start)
			start = ft_check_line(line);
		if (!start && !ft_check_content(line))
		{
			ft_putendl_fd("Error! Invalid content.", 2);
			free(line);
			close(fd);
			return (1);
		}
		if (start && !ft_check_line(line))
			end = 1;
		if (end && !ft_check_if_empty(line))
		{
			ft_putendl_fd("Error! Trailing data end.", 2);
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/**
 * Checks if a line contains map content.
*/
int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

/**
 * Checks if a line is a texture line or a color line.
 * If it's neither, it's considered valid content.
*/
int ft_check_content(char *line)
{
	char	*temp;

	temp = ft_strtrim(line, " \n");
	if (!temp)
		return (1);
	if (temp[0] && !ft_check_texture(temp) && !ft_check_color(temp))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

/**
 * Checks if a line of the file is a texture specification line.
*/
int	ft_check_texture(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	return (0);
}

/**
 * Checks if a line of the file is a color specification line.
*/
int	ft_check_color(char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

/**
 * Checks if a line is empty.
*/
int	ft_check_if_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
