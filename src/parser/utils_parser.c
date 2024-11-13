/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:24:15 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:40:20 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Copies the map to a array of pointers, and returns that array
static char	**copy_map(char **map, int rows, int cols)
{
	char	**new_map;
	int		y;
	int		x;

	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	y = 0;
	while (y < rows)
	{
		new_map[y] = malloc((cols + 1) * sizeof(char));
		if (!new_map[y])
			free_array_char(new_map);
		x = 0;
		while (x < cols)
		{
			new_map[y][x] = map[y][x];
			x++;
		}
		new_map[y][x] = '\0';
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

// Flood Filling algorithm, fills the map with 1 and 2
static void	flood_fill_map(char **temp_map, int y, int x, t_data *data)
{
	if (temp_map[y][x] == '1' || temp_map[y][x] == '2')
		return ;
	else if (temp_map[y][x] == 'C')
		data->map.collumn_p--;
	else if (temp_map[y][x] == 'E')
	{
		data->map.exit_p = 1;
		return ;
	}
	else if (temp_map[y][x] == 'B')
		return ;
	temp_map[y][x] = '2';
	flood_fill_map(temp_map, y - 1, x, data);
	flood_fill_map(temp_map, y + 1, x, data);
	flood_fill_map(temp_map, y, x - 1, data);
	flood_fill_map(temp_map, y, x + 1, data);
}

// Checks if map is possible, if not maps gets cleaned
static void	check_flood_fill(char **temp_map, t_data *data)
{
	if (data->map.collumn_p != 0 || data->map.exit_p != 1)
	{
		free_array_char(temp_map);
		free_exit(data, "Error - Elements inaccessible by the player\n");
	}
	free_array_char(temp_map);
}

// checks for empty path, or in other words, beatable map
void	empty_path(t_data *data)
{
	char	**temp_map;

	temp_map = copy_map(data->map.map, data->map.rows, data->map.collumns);
	data->map.collumn_p = data->map.nb_collectables;
	flood_fill_map(temp_map, data->player.y, data->player.x, data);
	check_flood_fill(temp_map, data);
}

// Checks for the lenght of the str until NewLine
int	ft_strlen_no_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
