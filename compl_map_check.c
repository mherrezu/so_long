/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:42:06 by mherrezu          #+#    #+#             */
/*   Updated: 2023/09/15 13:17:39 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Start map's size and collectibles.
int	start_size_collect(t_game *game, char **map)
{
	int	i;
	int	j;
	int	collect;

	i = 0;
	collect = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	game->total_collect = collect;
	game->map_width = ft_strlen(map[0]) * 32;
	i = 0;
	while (map[i++])
		game->map_height = i * 32;
	if (game->total_collect == 0 || game->map_width == 0 || game->map_height == 0)
		return (1);
	return (0);
}

//To check the game's path can be done and finish.
int	check_path(t_game *game)
{
	int	*pos;
	int	*aux;

	pos = start_player(game->map);
	aux = start_player(game->aux_map);
	// ft_printf("\nMAP:\n");
	// print_map(game->map);
	// ft_printf("\nAUX MAP:\n");
	// print_map(game->aux_map);
	flood_fill(game, pos[1], pos[0]);
	// ft_printf("\nFLOOD AUX MAP:\n");
	// print_map(game->aux_map);
	if (flood_checker(game->aux_map) == 1)
	{
		// ft_printf("\nPATH INCORRECT!!!\n");
		free (aux);
		free (pos);
		free_map(game->aux_map);
		return (1);
	}
	free (aux);
	free (pos);
	free_map(game->aux_map);
	return (0);
}

//Look for P in the map (x,y)
int	*start_player(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)ft_calloc(1, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->aux_map[x][y] == '0' || game->aux_map[x][y] == 'C'
		|| game->aux_map[x][y] == 'E' || game->aux_map[x][y] == 'P')
	{
		game->aux_map[x][y] = 'X';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

int	flood_checker(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!(map[x][y] == '1' || map[x][y] == 'X' || map[x][y] == '0'))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
