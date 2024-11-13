/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:45:00 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:37:13 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Loads collectable image
static void	load_collectable(t_data *data)
{
	data->sprites.collectable.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/misc/collectible/chips/chips1.xpm",
			&data->sprites.collectable.width,
			&data->sprites.collectable.height);
	data->sprites.collectable2.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/misc/collectible/chips/chips2.xpm",
			&data->sprites.collectable2.width,
			&data->sprites.collectable2.height);
	data->sprites.collectable3.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/misc/collectible/chips/chips3.xpm",
			&data->sprites.collectable3.width,
			&data->sprites.collectable3.height);
	if (data->sprites.collectable.image == NULL
		|| data->sprites.collectable2.image == NULL
		|| data->sprites.collectable3.image == NULL)
		free_exit(data, "Error - Failed to load collectables.\n");
}

// Loads map images
static void	load_sprites(t_data *data)
{
	data->sprites.wall.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/terrain/wall.xpm", &data->sprites.wall.width,
			&data->sprites.wall.height);
	data->sprites.floor.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/terrain/grass.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
	data->sprites.exit_closed.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/misc/door/door_closed.xpm",
			&data->sprites.exit_closed.width,
			&data->sprites.exit_closed.height);
	data->sprites.exit_open.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/misc/door/door_open.xpm", &data->sprites.exit_open.width,
			&data->sprites.exit_open.height);
	if (data->sprites.floor.image == NULL || data->sprites.wall.image == NULL
		|| data->sprites.exit_closed.image == NULL
		|| data->sprites.exit_open.image == NULL)
		free_exit(data, "Error - Failed to load enviorment.\n");
	load_collectable(data);
}

// Loads player and enemy image on idle
static void	load_p_e(t_data *data)
{
	data->player.player_front.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/idle/idle_l.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_back.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/idle/idle.xpm", &data->player.player_back.width,
			&data->player.player_back.height);
	data->player.player_right.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/idle/idle.xpm", &data->player.player_right.width,
			&data->player.player_right.height);
	data->player.player_left.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/idle/idle_l.xpm", &data->player.player_left.width,
			&data->player.player_left.height);
	data->sprites.enemy.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/enemy/enemy_idle.xpm", &data->sprites.enemy.width,
			&data->sprites.enemy.height);
	if (data->player.player_front.image == NULL
		|| data->player.player_back.image == NULL
		|| data->player.player_right.image == NULL
		|| data->player.player_left.image == NULL
		|| data->sprites.enemy.image == NULL)
		free_exit(data, "Error - Failed to load player or enemy sprites.\n");
}

void	init_game(t_data *data)
{
	data->mlx_p = mlx_init();
	if (data->mlx_p == NULL)
		free_exit(data, "Error - mlx failed.");
	mlx_get_screen_size(data->mlx_p, &data->screen_width, &data->screen_height);
	if (((data->map.rows * TILE_SIZE) + 16) > data->screen_height
		|| ((data->map.collumns * TILE_SIZE) + 16) > data->screen_width)
		free_exit(data, "Error - Window size larger than screen size.\n");
	data->window_p = mlx_new_window(data->mlx_p, data->map.collumns * TILE_SIZE,
			data->map.rows * TILE_SIZE, "so_long");
	if (data->window_p == NULL)
		free_exit(data, "Error - Impossible initiate the window.\n");
	load_sprites(data);
	load_p_e(data);
	draw_images(data);
	player_movement_image_front(data);
	player_movement_image_left(data);
	call_hooks(data);
}
