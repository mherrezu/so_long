/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariah. <mariah.@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:59 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/19 18:14:58 by mariah.          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;	
	}
	free(map);
}

int	map_checker(t_game map)
{
	if (empty_map(map) == 1)
		return (ft_printf(EMPTY_ERROR), 1);
	if (rectang_map(map) == 1)
		return (ft_printf(RECT_ERROR), 1);
	if (wrong_map(map) == 1)
		return (ft_printf(WRONG_ERROR), 1);
	if (walls_map(map) == 1)
		return (ft_printf(WALL_ERROR), 1);
	if (min_tiles(map) == 1)
		return (ft_printf(MIN_COMP_ERROR), 1);
	return (0);
}

char	**get_map(char *file_map)
{
	int		i;
	int		fd;
	char	**temp;
	char	**map;

	i = 0;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		return (0);
	temp = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp)
		return (0);
	i = read(fd, temp, BUFF_SIZE);
	if (i == -1 || i == 0)
	{
		free(temp);
		return (0);
	}
	map = ft_split(temp, '\n');
	free(temp);
	close(fd);
	return (map);
}

char	check_extension_file(char file_name)
{
	int	i;

	i = ft_strlen(file_name) - 1;
	if (file_name[i] != 'r' || file_name[i - 1] != 'e'
		|| file_name[i - 2] != 'b'
		|| file_name[i - 3] != '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(PARAM_ERROR), 1);
	if (check_extension_file(argv[1]) == 1)
		return (ft_printf(EXT_ERROR), 1);
	game.map = get_map(argv[1]);
	if (!game.map)
		return (1);
	if (map_checker(game.map) == 1)
		return (free_map(game.map), 1);
	print_map(game.map);
	return (0);
}

void print_map(t_game map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}