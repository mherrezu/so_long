/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariah. <mariah.@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:14 by mherrezu          #+#    #+#             */
/*   Updated: 2023/06/19 17:57:39 by mariah.          ###   ########.fr       */
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
