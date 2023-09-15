/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:14:47 by mherrezu          #+#    #+#             */
/*   Updated: 2023/09/15 13:50:34 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "print_libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// # define MAP_EXIT 'E'
// # define MAP_ENTRY 'P'
// # define MAP_COLLECTIBLE 'C'
// # define MAP_WALL '1'
// # define MAP_FLOOR '0'

# define PARAM_ERROR "Error - Incorrect number of parameters\n"
# define EXT_ERROR "Error - File has invalid file extension\n"
# define EMPTY_ERROR "Error - Map is empty\n"
# define RECT_ERROR "Error - Map is not rectangle.\n"
# define ITEMS_ERROR "Error - Map have the wrongs components\n"
# define WALL_ERROR "Error - Map don't have close walls\n"
# define MIN_COMP_ERROR "Error - You don't have the correct components\n"
# define PATH_ERROR "Error - There is not a valid path\n"
# define MAP_SUCCESS "SUCCESS! - Your map is perfect!\n"

# define BUFF_SIZE 10000
# define MOVE		32

typedef struct s_game
{
	struct s_textures	*textures;
	struct s_images		*image;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					counter_collect;
	int					move_count;
	int					total_collect;
	char				**aux_map;
}						t_game;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;
	mlx_texture_t	*finish;
}					t_textures;

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*collect;
	mlx_image_t		*exit;
	mlx_image_t		*finish;
}					t_images;

//MAIN.C 
int		map_checker(char **map);
void	free_map(char **map);
char	**get_map(char *file_map);
char	check_extension_file(char *file_name);
int		main(int argc, char **argv);
void	print_map(char **map); //DELETE LATER

//BASIC_MAP_CHECK.C
int		empty_check(char **map);
int		rectang_check(char **map);
int		items_check(char **map);
int		walls_check(char **map);
int		min_tiles_check(char **map);

//COMPL_MAP_CHECK.C
int		start_size_collect(t_game *game, char **map);
int		check_path(t_game *game);
int		*start_player(char **map);
void	flood_fill(t_game *game, int x, int y);
int		flood_checker(char **map);

// GAME_VISUAL.C
int		start_game(t_game *game);
void	start_textures(t_game *game);
void	start_images(t_game *game);
void	visualize_map(t_game *game, t_images *image);

#endif