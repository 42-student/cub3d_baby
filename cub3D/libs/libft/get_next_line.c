/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:01:07 by smargine          #+#    #+#             */
/*   Updated: 2023/09/09 13:34:07 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
	}
	buffer = ft_read_text(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = ft_start_new(buffer);
	return (line);
}

char	*ft_read_text(int fd, char *buffer)
{
	char	*rd_buf;
	int		rd_bytes;

	rd_bytes = 1;
	rd_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!rd_buf)
		return (NULL);
	while (rd_bytes > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		rd_bytes = read(fd, rd_buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			free(rd_buf);
			return (NULL);
		}
		rd_buf[rd_bytes] = '\0';
		buffer = ft_strjoin_gnl(buffer, rd_buf);
	}
	free(rd_buf);
	return (buffer);
}

char	*ft_read_line(char *buffer)
{
	char	*the_line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	the_line = malloc(sizeof(char) * (i + 1));
	if (!the_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		the_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		the_line[i++] = '\n';
	the_line[i] = '\0';
	return (the_line);
}

char	*ft_start_new(char *buffer)
{
	char	*start_new;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	start_new = ft_substr_gnl(buffer, i, ft_strlen_gnl(buffer) - i);
	free(buffer);
	return (start_new);
}
