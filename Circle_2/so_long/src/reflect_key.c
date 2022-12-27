/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:11:26 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 17:13:16 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	reflect_key(t_game *game)
{
	int	x;
	int	y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (game->map.coordinate[y][x] == COLLECTION)
	{
		game->map.coordinate[y][x] = DEAD_COLLECTION;
		--game->object.collection.count;
	}
	if (game->map.coordinate[y][x] == EXIT)
	{
		if (!game->object.collection.count)
			game->flag.scene = GAME_ENDING;
	}
}

void	move_north(t_game *game)
{
	int	x;
	int	y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (-1 < game->object.player.y - 1
		&& game->map.coordinate[y - 1][x] != WALL)
	{
		--game->object.player.y;
	}
	reflect_key(game);
	game->flag.move = TRUE;
}

void	move_west(t_game *game)
{
	int	x;
	int	y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (game->object.player.y + 1 < game->map.rows
		&& game->map.coordinate[y + 1][x] != WALL)
	{
		++game->object.player.y;
	}
	reflect_key(game);
	game->flag.move = TRUE;
}

void	move_south(t_game *game)
{
	int	x;
	int	y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (-1 < game->object.player.x - 1
		&& game->map.coordinate[y][x - 1] != WALL)
	{
		--game->object.player.x;
		game->object.player.direction = LEFT;
	}
	reflect_key(game);
	game->flag.move = TRUE;
}

void	move_east(t_game *game)
{
	int	x;
	int	y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (x + 1 < game->map.cols
		&& game->map.coordinate[y][x + 1] != WALL)
	{
		++game->object.player.x;
		game->object.player.direction = RIGHT;
	}
	reflect_key(game);
	game->flag.move = TRUE;
}
