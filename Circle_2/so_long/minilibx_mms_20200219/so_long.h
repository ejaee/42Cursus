/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:39:50 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/17 19:38:38 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "gnl/gnl.h"
# include "mlx.h"
# include <fcntl.h>

# define TRUE	0
# define FALSE	1

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define RESET	"\x1b[0m"

typedef struct s_coord
{
	int	y;
	int	x;

}	t_coord;

typedef struct s_map
{
	int		cols;
	int		rows;
	t_coord	**coord_info;

}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map_info;
}	t_game;

#endif
