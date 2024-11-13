/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_on_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:58:01 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 15:26:41 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Writes the moves on screen
void	put_moves_screen(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->moves);
	mlx_put_image_to_window(data->mlx_p, data->window_p,
		data->sprites.wall.image, 0, 0);
	mlx_string_put(data->mlx_p, data->window_p, 15, 15, 16766720, moves);
	free(moves);
}

// Writes the first move (0) on screen
void	initialize_moves_screen(t_data data)
{
	mlx_string_put(data.mlx_p, data.window_p, 15, 15, 16766720, "0");
}
