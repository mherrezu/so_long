/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariah. <mariah.@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:14 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/20 19:50:28 by mariah.          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_check(t_game map)
{
	if (!map[0])
		return (1);
	return (0);
}
//Map must be rectangular
int	rectang_check(t_game map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}
//Map is composed of 1, 0, E, P and C
int	items_check(t_game map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '1' || map[i][j] == '0'
				|| map[i][j] == 'E' || map[i][j] == 'P'
				|| (map[i][j] == 'C')))
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

//Map must be surrounded by walls(1)
int	walls_check(t_game map)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	x = ft_strlen(map[0]);
	y = 0;
	while (map[y])
		y++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[y - 1][i] != '1')
			return (1);
		i++;
	}
	j = 0;
	//REVISAR ESTE WHILE
	while (i < (line - 1))
	{
		if (map[j][0] != '1' || map[j][x-1] != '1')
			return (1);
		j++;
	}
	return (0);
}

//Map must have at least 1 entry, 1 exit and 1 collectible
int	min_tiles_check(t_game map)
{
	int	i;
	int	j;
	int	entry_exit;
	int	collect;

	entry_exit = 0;
	collect= 0;
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
		i+t+;
	}

	if (entry_exit != 2 || collect < 1)
		return (1);
	return (0);
}
