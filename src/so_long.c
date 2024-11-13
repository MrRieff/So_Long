/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:00:01 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:09:34 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Initializes the sprites with a specific size,
	defined by the macro Tile_size in the header file */
static void	initialization_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->moves = 1;
	data->sprites.floor.width = TILE_SIZE;
	data->sprites.floor.height = TILE_SIZE;
	data->sprites.wall.width = TILE_SIZE;
	data->sprites.wall.height = TILE_SIZE;
	data->sprites.collectable.width = TILE_SIZE;
	data->sprites.collectable.height = TILE_SIZE;
	data->sprites.exit_closed.width = TILE_SIZE;
	data->sprites.exit_closed.height = TILE_SIZE;
	data->sprites.exit_open.width = TILE_SIZE;
	data->sprites.exit_open.height = TILE_SIZE;
	data->sprites.enemy.width = TILE_SIZE;
	data->sprites.enemy.height = TILE_SIZE;
}

/*  Initializes the player sprites with a specific size,
	defined by the macro Tile_size in the header file */
static void	initialization_player(t_data *data)
{
	data->player.player_front.width = TILE_SIZE;
	data->player.player_front.height = TILE_SIZE;
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialization_data(&data);
	initialization_player(&data);
	if (argc != 2)
		free_exit(&data, "Error\n");
	check_load_map(&data, argv[1]);
	init_game(&data);
	initialize_moves_screen(data);
	mlx_loop_hook(data.mlx_p, animation_chips, &data);
	mlx_loop(data.mlx_p);
}
