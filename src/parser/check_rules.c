/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:18:28 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:05:10 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*  When the player or exit character is located,
	they are added to their respectives attributes */
static void	check_char(t_data *data, int y, int x, char c)
{
	if (c == 'P')
	{
		data->player.x = x;
		data->player.y = y;
	}
	if (c == 'E')
	{
		data->map.exit_x = x;
		data->map.exit_y = y;
	}
}

// Checks if the elements (of P or E) are the correct ammount
static void	check_nb_elements(t_data *data, char c)
{
	int	y;
	int	x;
	int	counter;

	y = -1;
	counter = 0;
	while (++y < data->map.rows)
	{
		x = 0;
		while (x < data->map.collumns)
		{
			if (data->map.map[y][x] == c)
			{
				counter++;
				check_char(data, y, x, c);
			}
			x++;
		}
	}
	if (counter != 1)
		free_exit(data, "Error - Invalid number player or exits\n");
}

// Checks if there are at least on collectable
static void	check_num_c(t_data *data, char c)
{
	int	y;
	int	x;
	int	counter;

	y = 0;
	counter = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.collumns)
		{
			if (data->map.map[y][x] == c)
				counter++;
			x++;
		}
		y++;
	}
	if (counter < 1)
		free_exit(data, "Error - Invalid number of collectables\n");
	data->map.nb_collectables = counter;
}

// Checks if the elements are valid
void	valid_chars(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.collumns)
		{
			if (data->map.map[y][x] != '0' && data->map.map[y][x] != '1'
				&& data->map.map[y][x] != 'P' && data->map.map[y][x] != 'E'
				&& data->map.map[y][x] != 'C' && data->map.map[y][x] != 'B')
				free_exit(data, "Error - Invalid elements\n");
			x++;
		}
		y++;
	}
	check_nb_elements(data, 'P');
	check_nb_elements(data, 'E');
	check_num_c(data, 'C');
}

// Checks if map is surrounded by walls
void	check_walls(t_data *data)
{
	int	y;
	int	x;
	int	col;
	int	row;

	col = data->map.collumns - 1;
	row = data->map.rows - 1;
	x = 0;
	while (x < data->map.collumns)
	{
		if (data->map.map[0][x] != '1' || data->map.map[row][x] != '1')
			free_exit(data, "Error - Map isn't surrounded by walls\n");
		x++;
	}
	y = 0;
	while (y < data->map.rows)
	{
		if (data->map.map[y][0] != '1' || data->map.map[y][col] != '1')
			free_exit(data, "Error - Map isn't surrounded by walls\n");
		y++;
	}
}
