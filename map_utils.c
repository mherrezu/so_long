/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:14 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/12 17:50:31 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_map(t_game map)
{
	if (!map[0])
		return (1);
	return (0);
}

int	rectang_map(t_game map)
{
	
}

int	wrong_map(t_game map)
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

int	walls_map(t_game map)
{
	
}

int	min_tiles(t_game map)
{
	
}
