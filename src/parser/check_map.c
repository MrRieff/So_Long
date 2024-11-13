/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:19:45 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:09:18 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Checks if the map follows the rules
static void	check_map_criteria(t_data *data)
{
	valid_chars(data);
	check_walls(data);
	empty_path(data);
}

// Reads the map and places the info in the struct
static void	loading_map(t_data *data, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	data->map.map = malloc((data->map.rows + 1) * sizeof(char *));
	if (!data->map.map)
		free_exit(data, "Error - Malloc error.\n");
	while (i < data->map.rows)
	{
		line = get_next_line(fd);
		if (!line)
			free_exit(data, "Error - Reading line failed.\n");
		data->map.map[i] = malloc((data->map.collumns + 1) * sizeof(char));
		if (!data->map.map[i])
			free_exit(data, "Error - Malloc error.\n");
		j = -1;
		while (++j < data->map.collumns)
			data->map.map[i][j] = line[j];
		data->map.map[i][j] = '\0';
		free(line);
		i++;
	}
	data->map.map[i] = NULL;
}

// Checks if the map is in the correct shape
static void	check_map_shape(t_data *data, int fd)
{
	char	*line;
	int		check_cols;

	line = get_next_line(fd);
	if (!line)
		free_exit(data, "Error - File is empty.\n");
	data->map.collumns = ft_strlen_no_newline(line);
	while (line)
	{
		data->map.rows++;
		check_cols = ft_strlen_no_newline(line);
		if (data->map.collumns != check_cols)
		{
			free(line);
			free_exit(data, "Error - Isn't a rectangle.\n");
		}
		free(line);
		line = get_next_line(fd);
	}
}

// Checks if the map is a .ber file
static int	check_file_name(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(&file_name[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

// Error messages and executions
void	check_load_map(t_data *data, char *file_name)
{
	int	fd;

	if (check_file_name(file_name) != 1)
		free_exit(data, "Error - Wrong file name format\n");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		free_exit(data, "Error - File is not in the repository.\n");
	check_map_shape(data, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		free_exit(data, "Error - Could not re-open file.\n");
	loading_map(data, fd);
	close(fd);
	check_map_criteria(data);
}
