/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:58:42 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:36:01 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Creates background, putting grass in the whole map first and then the walls
static void	draw_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			mlx_put_image_to_window(data->mlx_p, data->window_p,
				data->sprites.floor.image, x * TILE_SIZE, y * TILE_SIZE);
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_p, data->window_p,
					data->sprites.wall.image, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

// Creates enemies, collectables and exit
static void	draw_elements(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_p, data->window_p,
					data->sprites.exit_closed.image, x * TILE_SIZE, y
					* TILE_SIZE);
			if (data->map.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_p, data->window_p,
					data->sprites.collectable.image, x * TILE_SIZE, y
					* TILE_SIZE);
			if (data->map.map[y][x] == 'B')
				mlx_put_image_to_window(data->mlx_p, data->window_p,
					data->sprites.enemy.image, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

// Creates player, in the idle position
void	draw_player(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->player.player_back.image, data->player.x * TILE_SIZE,
			data->player.y * TILE_SIZE);
	else if (keysym == XK_s || keysym == XK_Down)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->player.player_front.image, data->player.x * TILE_SIZE,
			data->player.y * TILE_SIZE);
	else if (keysym == XK_a || keysym == XK_Left)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->player.player_left.image, data->player.x * TILE_SIZE,
			data->player.y * TILE_SIZE);
	else if (keysym == XK_d || keysym == XK_Right)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->player.player_right.image, data->player.x * TILE_SIZE,
			data->player.y * TILE_SIZE);
}

// Calls everything for the visual part
void	draw_images(t_data *data)
{
	draw_background(data);
	draw_elements(data);
	draw_player(XK_s, data);
}
