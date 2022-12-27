/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:05:41 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 13:49:07 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	init_tile_img(t_game *game)
{
	int	x;
	int	y;

	game->object.opening.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/opening.xpm", &x, &y);
	game->object.ending.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/ending.xpm", &x, &y);
	game->object.kill.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/killing.xpm", &x, &y);
	game->object.tile_0.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/tile_0.xpm", &x, &y);
	game->object.tile_1.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/tile1.xpm", &x, &y);
	game->object.exit_0.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/exit_0.xpm", &x, &y);
	game->object.exit_1.ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/exit_1.xpm", &x, &y);
}

void	init_player_img(t_game *game)
{
	int	width;
	int	height;

	game->object.player.img[RIGHT][0].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/c_r0.xpm", &width, &height);
	game->object.player.img[RIGHT][1].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/c_r1.xpm", &width, &height);
	game->object.player.img[RIGHT][2].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/c_r2.xpm", &width, &height);
	game->object.player.img[LEFT][0].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/c_l0.xpm", &width, &height);
	game->object.player.img[LEFT][1].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/c_l1.xpm", &width, &height);
	game->object.player.img[LEFT][2].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/c_l2.xpm", &width, &height);
}

void	init_collection_img(t_game *game)
{
	int	width;
	int	height;

	game->object.collection.img[0].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/collection_0.xpm", &width, &height);
	game->object.collection.img[1].ptr = mlx_xpm_file_to_image \
		(game->mlx_ptr, "./img/collection_1.xpm", &width, &height);
}

void	init_img(t_game *game)
{
	init_tile_img(game);
	init_player_img(game);
	init_collection_img(game);
}
