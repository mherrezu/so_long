/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariah. <mariah.@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:24:32 by mherrezu          #+#    #+#             */
/*   Updated: 2023/11/12 12:52:54 by mariah.          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function contiguously allocates enough space for count objects that are size 
// bytes of memory each and returns a pointer to the allocated memory. The 
// allocated memory is filled with bytes of value zero.
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*ptr;
	// size_t	i;

	// i = 0;
	ptr = (int *) malloc (count * size);
	if (!ptr)
	{
		free (ptr);
		return (NULL);
	}
	else
	{
		ft_bzero (ptr, count * size);
		return (ptr);
	}
}
