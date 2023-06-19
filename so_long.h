/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariah. <mariah.@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:14:47 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/19 18:15:34 by mariah.          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./print_libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// # define MAP_EXIT 'E'
// # define MAP_ENTRY 'P'
// # define MAP_COLLECTABLE 'C'
// # define MAP_WALL '1'
// # define MAP_FLOOR '0'

# define PARAM_ERROR "Error - Incorrect number of parameters\n"
# define EXT_ERROR "Error - File has invalid file extension\n"
# define EMPTY_ERROR "Error - Map is empty\n"
# define RECT_ERROR "Error - Map is not rectangle.\n"
# define WRONG_ERROR "Error - Map have the wrongs components\n"
# define WALL_ERROR "Error - Map don't have close walls\n"
# define MIN_COMP_ERROR "Error - You don't have the correct components\n"
# define PATH_ERROR "Error - There is not a valid path\n"

# define BUFF_SIZE 10000
# define MOVE		32

typedef struct s_game
{
	char				**map;
}					t_game;

//MAIN.C 
int		map_checker(t_game map);
void	free_map(char **map);
char	**get_map(char *file_map);
char	check_extension_file(char file_name);
int		main(int argc, char **argv);
void	print_map(char **map); //DELETE LATER

//MAP_UTILS.C
int		empty_map(t_game map);
int		rectang_map(t_game map);
int		rectang_map(t_game map);
int		wrong_map(t_game map);
int		walls_map(t_game map);
int		min_tiles(t_game map);

#endif
