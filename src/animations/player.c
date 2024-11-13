/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:56:24 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:38:38 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Loads animation sprite image
void	player_movement_image_front(t_data *data)
{
	data->player.player_front_walk1.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk1.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_front_walk2.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk2.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_front_walk3.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk3.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_front_walk4.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk4.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	if (data->player.player_front_walk1.image == NULL
		|| data->player.player_front_walk2.image == NULL
		|| data->player.player_front_walk3.image == NULL
		|| data->player.player_front_walk4.image == NULL)
		free_exit(data,
			"Could not load player walking forwards animation sprites!\n");
}

// Loads animation sprite image
void	player_movement_image_left(t_data *data)
{
	data->player.player_left_walk1.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk1_l.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_left_walk2.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk2_l.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_left_walk3.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk3_l.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	data->player.player_left_walk4.image = mlx_xpm_file_to_image(data->mlx_p,
			"assets/player/walk/walk4_l.xpm", &data->player.player_front.width,
			&data->player.player_front.height);
	if (data->player.player_left_walk1.image == NULL
		|| data->player.player_left_walk2.image == NULL
		|| data->player.player_left_walk3.image == NULL
		|| data->player.player_left_walk4.image == NULL)
		free_exit(data,
			"Could no load player walking left animation sprites!\n");
}

// Switches image between moves
static void	*player_movement_up(t_data *data, int anim_frame)
{
	void	*current_image;

	current_image = 0;
	if (anim_frame == 0)
		current_image = data->player.player_front_walk1.image;
	else if (anim_frame == 1)
		current_image = data->player.player_front_walk2.image;
	else if (anim_frame == 2)
		current_image = data->player.player_front_walk3.image;
	else if (anim_frame == 3)
		current_image = data->player.player_front_walk4.image;
	return (current_image);
}

// Switches image between moves
static void	*player_movement_down(t_data *data, int anim_frame)
{
	void	*current_image;

	current_image = 0;
	if (anim_frame == 0)
		current_image = data->player.player_left_walk1.image;
	else if (anim_frame == 1)
		current_image = data->player.player_left_walk2.image;
	else if (anim_frame == 2)
		current_image = data->player.player_left_walk3.image;
	else if (anim_frame == 3)
		current_image = data->player.player_left_walk4.image;
	return (current_image);
}

// Calls the animation for the moves
void	player_movement(t_data *data, int keysym)
{
	static int	anim_frame = 0;
	void		*current_image;

	current_image = NULL;
	anim_frame = (anim_frame + 1) % 4;
	if (keysym == XK_w || keysym == XK_Up || keysym == XK_Right
		|| keysym == XK_d)
		current_image = player_movement_up(data, anim_frame);
	else if (keysym == XK_s || keysym == XK_Down || keysym == XK_a
		|| keysym == XK_Left)
		current_image = player_movement_down(data, anim_frame);
	mlx_put_image_to_window(data->mlx_p, data->window_p, current_image,
		data->player.x * TILE_SIZE, data->player.y * TILE_SIZE);
}
