/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:24:47 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:31:55 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//----LIBRARIES----
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

//----MY-IMPORTS----
# include "../libraries/libft/includes/libft.h"
# include "../libraries/minilibx/mlx.h"
# include "../libraries/minilibx/mlx_int.h"

//----TILE-SIZE-----
# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

//-----STRUCTS------
typedef struct s_image
{
	void		*image;

	char		*address;

	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_image;

typedef struct s_map
{
	char		**map;

	int			collumns;
	int			rows;
	int			nb_collectables;
	int			collumn_p;
	int			exit_p;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;

	t_image		player_front;
	t_image		player_back;
	t_image		player_left;
	t_image		player_right;

	t_image		player_front_walk1;
	t_image		player_front_walk2;
	t_image		player_front_walk3;
	t_image		player_front_walk4;
	t_image		player_left_walk1;
	t_image		player_left_walk2;
	t_image		player_left_walk3;
	t_image		player_left_walk4;

	void		*current_image;

}				t_player;

typedef struct s_sprites
{
	t_image		floor;
	t_image		wall;
	t_image		collectable;
	t_image		collectable2;
	t_image		collectable3;
	t_image		exit_closed;
	t_image		exit_open;
	t_image		enemy;
}				t_sprites;

typedef struct s_data
{
	void		*mlx_p;
	void		*window_p;

	t_map		map;

	t_player	player;

	t_sprites	sprites;

	int			screen_width;
	int			screen_height;
	int			moves;
}				t_data;

//-----FUNCTIONS-----

// ERROR
void			free_exit(t_data *data, char *str);
void			free_map(t_data *data);
void			free_array_char(char **array);
void			free_sprites(t_data *data);
void			free_player(t_data *data);

// INIT
void			init_game(t_data *data);

// HOOKS
void			call_hooks(t_data *data);

// PARSER
void			check_load_map(t_data *data, char *file_name);
void			valid_chars(t_data *data);
void			check_walls(t_data *data);
void			empty_path(t_data *data);
int				ft_strlen_no_newline(char *str);

// IMAGE
void			draw_player(int keysym, t_data *data);
void			draw_images(t_data *data);

// ANIMATION
bool			fps(float milliseconds);
int				animation_chips(t_data *data);
void			player_movement(t_data *data, int keysym);
void			player_movement_image_front(t_data *data);
void			player_movement_image_left(t_data *data);
void			free_player_animation(t_data *data);

// Score
void			initialize_moves_screen(t_data data);
void			put_moves_screen(t_data *data);

#endif
