/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:59 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/29 14:16:06 by mherrezu         ###   ########.fr       */
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

int	map_checker(char **map)
{
	if (empty_check(map) == 1)
		return (ft_printf(EMPTY_ERROR), 1);
	if (rectang_check(map) == 1)
		return (ft_printf(RECT_ERROR), 1);
	if (items_check(map) == 1)
		return (ft_printf(ITEMS_ERROR), 1);
	if (walls_check(map) == 1)
		return (ft_printf(WALL_ERROR), 1);
	if (min_tiles_check(map) == 1)
		return (ft_printf(MIN_COMP_ERROR), 1);
	ft_printf("MAP is correct. No empty, rectangular, all items, walls and tiles.\n");
	return (0);
}

char	**get_map(char *file_map)
{
	int		i;
	int		fd;
	char	*aux;
	char	**map;
	i = 0;
	aux = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!aux)
		return (0);
	fd = open(file_map, O_RDONLY);
	//ft_printf("FD: %i\n", fd);
	if (fd < 0)
		return (0);
	i = read(fd, aux, BUFF_SIZE);
	if (i == -1 || i == 0)
	{
		free(aux);
		return (0);
	}
	map = ft_split((const char *)aux, '\n');
	print_map(map);
	free(aux);
	close(fd);
	return (map);
}

char	check_extension_file(char *file_name)
{
	int	i;

	i = ft_strlen((const char*)file_name) - 1;
	if (file_name[i] != 'r' || file_name[i - 1] != 'e'
		|| file_name[i - 2] != 'b'
		|| file_name[i - 3] != '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	system("leaks -q so_long");
	if (argc != 2)
		return (ft_printf(PARAM_ERROR), 1);
	if (check_extension_file(argv[1]) == 1)
		return (ft_printf(EXT_ERROR), 1);
	game.map = get_map(argv[1]);
	if (!game.map)
		return (1);
	if (map_checker(game.map) == 1)
		return (free_map(game.map), 1);
	start_size_collect(game, game.map);
	check_path(game);
	return (0);
}

void print_map(char **map)
{
	int	i;
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
