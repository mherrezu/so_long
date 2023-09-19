/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:46:37 by mherrezu          #+#    #+#             */
/*   Updated: 2023/09/19 14:53:10 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	adapt_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		go_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		go_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		go_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		go_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	manage_collect_exit(game);
}

void	go_up(t_game *game)
{
	if (game->map[game->image->player->instances->y / 32 - 1]
		[game->image->player->instances->x / 32] != '1')
	{
		game->image->player->instances->y -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->image->player->instances->y / 32 + 1]
		[game->image->player->instances->x / 32] != '1')
	{
		game->image->player->instances->y += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	go_left(t_game *game)
{
	if (game->map[game->image->player->instances->y / 32]
		[game->image->player->instances->x / 32 - 1] != '1')
	{
		game->image->player->instances->x -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	go_right(t_game *game)
{
	if (game->map[game->image->player->instances->y / 32]
		[game->image->player->instances->x / 32 + 1] != '1')
	{
		game->image->player->instances->x += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}
