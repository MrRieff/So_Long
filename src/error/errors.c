/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:37:43 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:32:11 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Frees everything and sends an error message
void	free_exit(t_data *data, char *str)
{
	if (str && str[0] != '\0')
		ft_putstr_fd(str, 2);
	if (!data)
		exit(0);
	free_sprites(data);
	free_player(data);
	if (data->map.map)
		free_map(data);
	if (data->window_p)
		mlx_destroy_window(data->mlx_p, data->window_p);
	if (data->mlx_p)
	{
		mlx_destroy_display(data->mlx_p);
		free(data->mlx_p);
	}
	exit(0);
}

// frees map
void	free_map(t_data *data)
{
	int	idx;

	idx = 0;
	while (data->map.map[idx])
	{
		free(data->map.map[idx]);
		idx++;
	}
	free(data->map.map);
}

// frees the array for the flood fill check
void	free_array_char(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}
