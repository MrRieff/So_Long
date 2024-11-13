/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:43 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:18:11 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Destroys image for the collectables, doors, and enemies
void	free_sprites(t_data *data)
{
	if (data->sprites.floor.image)
		mlx_destroy_image(data->mlx_p, data->sprites.floor.image);
	if (data->sprites.wall.image)
		mlx_destroy_image(data->mlx_p, data->sprites.wall.image);
	if (data->sprites.collectable.image)
		mlx_destroy_image(data->mlx_p, data->sprites.collectable.image);
	if (data->sprites.collectable2.image)
		mlx_destroy_image(data->mlx_p, data->sprites.collectable2.image);
	if (data->sprites.collectable3.image)
		mlx_destroy_image(data->mlx_p, data->sprites.collectable3.image);
	if (data->sprites.exit_closed.image)
		mlx_destroy_image(data->mlx_p, data->sprites.exit_closed.image);
	if (data->sprites.exit_open.image)
		mlx_destroy_image(data->mlx_p, data->sprites.exit_open.image);
	if (data->sprites.enemy.image)
		mlx_destroy_image(data->mlx_p, data->sprites.enemy.image);
}

// Destroys idle image for player
void	free_player(t_data *data)
{
	if (data->player.player_front.image)
		mlx_destroy_image(data->mlx_p, data->player.player_front.image);
	if (data->player.player_back.image)
		mlx_destroy_image(data->mlx_p, data->player.player_back.image);
	if (data->player.player_left.image)
		mlx_destroy_image(data->mlx_p, data->player.player_left.image);
	if (data->player.player_right.image)
		mlx_destroy_image(data->mlx_p, data->player.player_right.image);
	free_player_animation(data);
}

// Destroys the animation images for the player
void	free_player_animation(t_data *data)
{
	if (data->player.player_front_walk1.image)
		mlx_destroy_image(data->mlx_p, data->player.player_front_walk1.image);
	if (data->player.player_front_walk2.image)
		mlx_destroy_image(data->mlx_p, data->player.player_front_walk2.image);
	if (data->player.player_front_walk3.image)
		mlx_destroy_image(data->mlx_p, data->player.player_front_walk3.image);
	if (data->player.player_front_walk4.image)
		mlx_destroy_image(data->mlx_p, data->player.player_front_walk4.image);
	if (data->player.player_left_walk1.image)
		mlx_destroy_image(data->mlx_p, data->player.player_left_walk1.image);
	if (data->player.player_left_walk2.image)
		mlx_destroy_image(data->mlx_p, data->player.player_left_walk2.image);
	if (data->player.player_left_walk3.image)
		mlx_destroy_image(data->mlx_p, data->player.player_left_walk3.image);
	if (data->player.player_left_walk4.image)
		mlx_destroy_image(data->mlx_p, data->player.player_left_walk4.image);
}
