/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:00:18 by mherrezu          #+#    #+#             */
/*   Updated: 2023/09/27 18:32:33 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Start map's collectibles.
int	start_collect(t_game *game, char **map)
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
	if (game->total_collect == 0)
		return (1);
	return (0);
}

//Map must have only 1 entry, 1 exit and  at least 1 collectible
int	min_items_check(char **map)
{
	int	i;
	int	j;
	int	entry_exit;
	int	collect;

	entry_exit = 0;
	collect = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P')
				entry_exit++;
			if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (entry_exit != 2 || collect < 1)
		return (1);
	return (0);
}

//Manage the collects and the exit.
void	manage_collect_exit(t_game *game)
{
	if (game->map[game->image->player->instances->y / 32]
		[game->image->player->instances->x / 32] == 'C')
	{
		change_view(game);
		game->map[game->image->player->instances->y / 32]
		[game->image->player->instances->x / 32] = '0';
		game->counter_collect += 1;
		if (game->counter_collect == game->total_collect)
		{
			game->image->exit->instances->enabled = false;
			game->image->finish->instances->enabled = true;
		}
	}
	if (game->map[game->image->player->instances->y / 32]
		[game->image->player->instances->x / 32] == 'E')
	{
		if (game->counter_collect == game->total_collect)
			mlx_close_window(game->mlx);
	}
}

// Check if the coordinates of instances[i] is equal player's coordinates
// to change the visibility of the collect.
void	change_view(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->total_collect;
	while (i < count)
	{
		if (((game->image->collect->instances[i].y
					== game->image->player->instances->y)
				&& (game->image->collect->instances[i].x
					== game->image->player->instances->x))
			&& game->image->collect->instances[i].enabled == true)
		{
			count--;
			game->image->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}
