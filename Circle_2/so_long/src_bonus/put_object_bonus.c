/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_object_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:06:38 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/27 17:34:44 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	put_fixed_object(t_game *game, int x, int y)
{
	if (game->map.coordinate[y][x] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->object.tile_1.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->object.tile_0.ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	put_unfixed_object(t_game *game, int x, int y, int direction)
{
	put_collection(game, x, y);
	put_exit(game, x, y);
	put_player(game, direction);
}

void	put_collection(t_game *game, int x, int y)
{
	if (game->map.coordinate[y][x] == COLLECTION)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->object.collection.img[0].ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.coordinate[y][x] == DEAD_COLLECTION)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->object.collection.img[1].ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	put_exit(t_game *game, int x, int y)
{
	if (game->map.coordinate[y][x] == EXIT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->object.tile_0.ptr, x * TILE_SIZE, y * TILE_SIZE);
		if (game->object.collection.count)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->object.exit_0.ptr, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->object.exit_1.ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	put_player(t_game *game, int direction)
{
	int		x;
	int		y;
	void	*img_ptr;

	x = game->object.player.x;
	y = game->object.player.y;
	img_ptr = game->object.player.img[direction][0].ptr;
	if (game->flag.move)
	{
		put_sprite_img(game, game->object.player.direction);
		game->flag.move = FALSE;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}
