/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:42:06 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/29 14:47:06 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Start map's size and collectibles.
void	start_size_collect(t_game game, char **map)
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
	game.total_collect = collect;
	game.map_width = ft_strlen(map[0]) * 32;
	i = 0;
	while (map[i++])
	game.map_height = i * 32;
}

//To check the game's path can be done and finish.
void	check_path(t_game game)
{
	game.aux_map = game.map;
	ft_printf("\nAUX MAP:\n");
	print_map(game.aux_map);
}

int		flood_check(char **map)
{
	
	
	return (0);
}

// void	start_player_pos(char **map)
// {
	
// }
