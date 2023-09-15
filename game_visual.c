/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:56:07 by mherrezu          #+#    #+#             */
/*   Updated: 2023/09/15 13:54:01 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game)
{
	// ft_printf("\nMAP:\n");
	// print_map(game->map);
	game->move_count = 0;
	game->counter_collect = 0;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!(game->mlx))
		return (1);
	start_textures(game);
	start_images(game);
	visualize_map(game, game->image);
	//mlx_key_hook(game->mlx, &mlx_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	// free_map(game->map);
	// free(game->textures);
	// free(game->image);
	return (0);
}

void	start_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->floor = mlx_load_png("./textures/floor.png");
	game->textures->wall = mlx_load_png("./textures/wall.png");
	game->textures->player = mlx_load_png("./textures/player.png");
	game->textures->collect = mlx_load_png("./textures/collect.png");
	game->textures->exit = mlx_load_png("./textures/exit.png");
	game->textures->finish = mlx_load_png("./textures/finish.png");
}

void	start_images(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_images));
	game->image->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->image->player = mlx_texture_to_image(game->mlx, 
			game->textures->player);
	game->image->collect = mlx_texture_to_image(game->mlx, 
			game->textures->collect);
	game->image->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	game->image->finish = mlx_texture_to_image(game->mlx, 
			game->textures->finish);
	mlx_delete_texture(game->textures->floor);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->collect);
	mlx_delete_texture(game->textures->exit);
	mlx_delete_texture(game->textures->finish);
}

void	visualize_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	// ft_printf("\nMAP VISUALIZE:\n");
	// print_map(game->map);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
			if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, image->player, x * 32, y * 32);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, image->collect, x * 32, y * 32);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
