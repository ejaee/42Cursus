/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:39:50 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/19 21:03:03 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "gnl/gnl.h"
# include "mlx.h"
# include "color.h"
# include <fcntl.h>

# include <stdio.h>


# define TRUE	1
# define FALSE	0

typedef struct s_coord
{
	int	y;
	int	x;
}	t_coord;

typedef struct s_cnt
{
	int	collect;
	int	exit;
	int	player;
}	t_cnt;

typedef struct s_img
{
	void	*ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_compo
{
	t_img img_1;
	t_img img_0;
	t_img img_c;
	t_img img_e;
	t_img img_p;
}	t_compo;

typedef struct s_map
{
	int		cols;
	int		rows;
	char	**coord;
	t_cnt	component;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map_info;
	t_compo	compo_img;
}	t_game;



#endif
