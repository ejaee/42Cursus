#ifndef MAIN3_H
# define MAIN3_H

# include "Libft/libft.h"
# include "gnl/gnl.h"
# include "./mlx/mlx.h"
# include "color.h"

# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define MAP_EXTENSION ".ber"
# define TILE_SIZE 64

typedef struct s_map {
    int rows;
    int cols;
    char **coordinate;
}   t_map;

typedef struct s_game {
    void *mlx_ptr;
    void *win_ptr;
    t_map   map_info;
}   t_game;


#endif
