/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:06:38 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/23 22:15:52 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_fixed_object(t_game *game, int x, int y)
{
	if (game->map.coordinate[y][x] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.tile_1.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.tile_0.ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	put_unfixed_object(t_game *game, int x, int y, int direction)
{
	put_collection(game, x, y);
	put_exit(game, x, y);
	put_player(game, x, y, direction);
}

void	put_collection(t_game *game, int x, int y)
{
	if (game->map.coordinate[y][x] == COLLECTION)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.collection.img[0].ptr, x * TILE_SIZE, y * TILE_SIZE);

	else if (game->map.coordinate[y][x] == DEAD_COLLECTION)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.collection.img[1].ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	put_exit(t_game *game, int x, int y)
{
	if	(game->map.coordinate[y][x] == EXIT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.tile_0.ptr, x * TILE_SIZE, y * TILE_SIZE);
		if (game->object.collection.count)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.exit_0.ptr, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.exit_1.ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	put_player(t_game *game, int width, int height, int direction)
{
	int i;

	i = -1;
	if (game->flag.move)
	{
		put_sprite_img(game, game->object.player.direction);
		game->flag.move = FALSE;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.player.img[direction][0].ptr, game->object.player.x * TILE_SIZE, game->object.player.y * TILE_SIZE);
}



