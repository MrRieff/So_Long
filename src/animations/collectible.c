/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:45:20 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:39:09 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Animates the image for the collectable
static void	chips(t_data *data, int x, int y, int frame)
{
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->sprites.collectable.image, x * TILE_SIZE, y * TILE_SIZE);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->sprites.collectable2.image, x * TILE_SIZE, y * TILE_SIZE);
	else if (frame == 2)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->sprites.collectable3.image, x * TILE_SIZE, y * TILE_SIZE);
	else if (frame == 3)
		mlx_put_image_to_window(data->mlx_p, data->window_p,
			data->sprites.collectable2.image, x * TILE_SIZE, y * TILE_SIZE);
}

// calls the animation
int	animation_chips(t_data *data)
{
	static int	frame = 0;
	int			y;
	int			x;

	if (!fps(0.18))
		return (0);
	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
			if (data->map.map[y][x] == 'C')
				chips(data, x, y, frame);
	}
	frame = (frame + 1) % 4;
	return (0);
}
