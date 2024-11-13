/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:26:16 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:40:00 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/* Refreshes the map to put the grass over the player or
 collectable and opens door when the collectables are 0 */
static void	update_img(t_data *data, int y, int x)
{
	data->map.map[y][x] = '0';
	data->map.nb_collectables--;
	if (data->map.nb_collectables == 0)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->sprites.exit_open.image, data->map.exit_x * TILE_SIZE,
			data->map.exit_y * TILE_SIZE);
}

/* Verifies if move is possible,
	and if you exit or die it will react accordingly */
static int	verify_move(t_data *data, int keysym)
{
	int	y;
	int	x;

	y = data->player.y;
	x = data->player.x;
	if (keysym == XK_w || keysym == XK_Up)
		y--;
	else if (keysym == XK_s || keysym == XK_Down)
		y++;
	else if (keysym == XK_a || keysym == XK_Left)
		x--;
	else if (keysym == XK_d || keysym == XK_Right)
		x++;
	else if (keysym != XK_Escape)
		return (1);
	if (data->map.map[y][x] == '1' || (data->map.map[y][x] == 'E'
			&& data->map.nb_collectables != 0))
		return (1);
	else if (data->map.map[y][x] == 'C')
		return (update_img(data, y, x), 0);
	else if (data->map.map[y][x] == 'B')
		free_exit(data, "Game Over!\n");
	else if (data->map.map[y][x] == 'E' && data->map.nb_collectables == 0)
		free_exit(data, "You Won!\n");
	return (0);
}

// Updates the move to the struct and prints moves to the terminal
static int	handle_key(int keysym, t_data *data)
{
	if (verify_move(data, keysym) != 0)
		return (0);
	put_moves_screen(data);
	mlx_put_image_to_window(data->mlx_p, data->window_p,
		data->sprites.floor.image, data->player.x * TILE_SIZE, data->player.y
		* TILE_SIZE);
	if (keysym == XK_Escape)
		free_exit(data, "Game Closed!\n");
	else if (keysym == XK_w || keysym == XK_Up)
		data->player.y--;
	else if (keysym == XK_s || keysym == XK_Down)
		data->player.y++;
	else if (keysym == XK_a || keysym == XK_Left)
		data->player.x--;
	else if (keysym == XK_d || keysym == XK_Right)
		data->player.x++;
	data->map.map[data->player.y][data->player.x] = 'P';
	ft_printf("Moves %d\n", data->moves++);
	player_movement(data, keysym);
	return (0);
}

// Closes the game
static int	press_cross(t_data *data)
{
	free_exit(data, "Game Closed!\n");
	return (0);
}

// Closes the game
void	call_hooks(t_data *data)
{
	mlx_hook(data->window_p, KeyPress, KeyPressMask, handle_key, data);
	mlx_hook(data->window_p, DestroyNotify, StructureNotifyMask, press_cross,
		data);
}
