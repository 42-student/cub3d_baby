/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebastian <sebastian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:24:18 by smargine          #+#    #+#             */
/*   Updated: 2024/02/26 20:47:18 by sebastian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define WIDTH 1280
# define HEIGHT 720

/**
 * This is the parsing struct.
 * 
 *  **map - 2D array representing the map layout.
 *  *no - path to north wall texture.
 *  *so - path to south wall texture.
 *  *we - path to west wall texture.
 *  *ea - path to east wall texture.
 *  f_flag - floor flag, indicates if the color is set or not.
 *  c_flag - ceiling flag, indicates if the color is set or not.
 *  f_color - floor color.
 *  c_color - ceiling color.
 *  map_width - the width of the map.
 *  map_height - the height of the map.
*/
typedef struct s_pars
{
	int		**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_flag;
	int		c_flag;
	int		f_color;
	int		c_color;
	int		map_width;
	int		map_height;
}	t_pars;

/**
 * This is the main struct.
 * To be continued... :)
*/
typedef struct s_data
{
	t_pars	pars;
}	t_data;

//	main.c
int		ft_parsing(char *file, t_pars *pars);

// PARSER - check_file.c
int		ft_check_extension(char *file);
int		ft_check_file(char *file);
int		ft_check_line(char *line);
int		ft_check_content(char *line);
int		ft_check_texture(char *line);
int		ft_check_color(char *line);
int		ft_check_if_empty(char *line);

// PARSER - pars_line.c
int		ft_pars_line(char *file, t_pars *pars);
int		ft_store_data_line(char *line, t_pars *pars);
int		ft_store_texture_line(char **line, t_pars *pars);
int		ft_store_color_line(char **line, t_pars *pars);
int		ft_validate_color(char **color);
int		ft_check_mandatory_data(t_pars *pars);
int		ft_check_identical_data(char *line, t_pars *pars);

// PARSER - check_map.c
int		ft_check_map(char *file, t_pars *pars);
void	ft_go_to_end(int fd);
int		ft_line_lenght(char *line);
int		ft_valid_char(char c);
int		ft_verify_map(t_pars *pars);
int		ft_invalid_char(t_pars *pars);
int		ft_starting_point(t_pars *pars);
int		ft_check_walls(t_pars *pars);

// PARSER - map_init.c
int		ft_alloc_map(t_pars *pars);
int		ft_map_init(char *file, t_pars *pars);
void	ft_fill_map(char *line, int *map);

// UTILS - free.c
void	ft_free_2d_arr(char	**arr);
void	ft_free_2d_int(int	**arr);

#endif