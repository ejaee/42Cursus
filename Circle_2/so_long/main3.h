#ifndef MAIN3_H
# define MAIN3_H

# include "Libft/libft.h"
# include "gnl/gnl.h"
# include "./mlx/mlx.h"
# include "key.h"
# include "color.h"

# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define MAP_EXTENSION ".ber"
# define TILE_SIZE 64

# define RIGHT 0
# define LEFT 1

# define DEAD 'c'

typedef struct s_flag
{
	int scene;

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
	t_img	opening_scene;
	t_img	tile_0;
	t_img	tile_1;
	t_img	exit_1;
	t_player	player;
	t_collection collection;

}	t_object;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coordinate;
}	t_map;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map_info;
	t_flag		flag;
	t_object	object;
}   t_game;


#endif
