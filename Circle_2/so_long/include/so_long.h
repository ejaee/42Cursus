/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:54:52 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 17:25:41 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/gnl.h"
# include "../mlx/mlx.h"
# include "key.h"
# include "color.h"
# include "file.h"
# include "map.h"
# include "put.h"

# define TRUE 1
# define FALSE 0

# define TILE_SIZE 64

# define RIGHT 0
# define LEFT 1

# define GAME_PLAYING 1
# define GAME_ENDING 2

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTION 'C'
# define EXIT 'E'
# define DEAD_COLLECTION 'c'

# define NORTH 0
# define WEST 1
# define SOUTH 2
# define EAST 3

typedef struct s_flag
{
	int scene;
	int player;
	int exit;
	int move;
}	t_flag;

typedef struct s_img
{
	void	*ptr;
}	t_img;

typedef struct s_collection
{
	t_img	img[2];
	int x;
	int y;
	int count;
}	t_collection;

typedef struct s_player
{
	t_img	img[2][3];
	int x;
	int y;
	int direction;
}	t_player;

typedef struct s_object
{
	t_img	ending;
	t_img	tile_0;
	t_img	tile_1;
	t_img	exit_0;
	t_img	exit_1;
	t_player	player;
	t_collection collection;
}	t_object;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_flag		flag;
	t_object	object;
}	t_game;

void	init_tile_img(t_game *game);
void	init_player_img(t_game *game);
void	init_collection_img(t_game *game);
void	init_img(t_game *game);

void	exit_error(char *error_msg);
int		open_file(char *file);

void	reflect_key(t_game *game);
void	move_north(t_game *game);
void	move_west(t_game *game);
void	move_south(t_game *game);
void	move_east(t_game *game);
int		press_key(int key_code, t_game *game);

#endif
