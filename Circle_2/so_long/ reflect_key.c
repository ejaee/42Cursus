/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    reflecte_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:11:26 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/23 21:31:04 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reflect_key(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (game->map.coordinate[y][x] == COLLECTION)
	{
		game->flag.kill = TRUE;
		game->map.coordinate[y][x] = DEAD_COLLECTION;
		--game->object.collection.count;
	}
	if (game->map.coordinate[y][x] == EXIT)
	{
		if (!game->object.collection.count)
			game->flag.scene = GAME_ENDING;
	}
	show_step_count(game->object.player.step.count);
}

void	move_north(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (-1 < game->object.player.y - 1
		&& game->map.coordinate[y - 1][x] != WALL)
	{
		--game->object.player.y;
		if (game->flag.scene == GAME_PLAYING)
			++game->object.player.step.count;
	}
	reflect_key(game);
	put_sprite_img(game, game->object.player.direction);
	game->flag.move = TRUE;
}

void	move_west(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (game->object.player.y + 1 < game->map.rows
		&& game->map.coordinate[y + 1][x] != WALL)
	{
		++game->object.player.y;
		if (game->flag.scene == GAME_PLAYING)
			++game->object.player.step.count;
	}
	reflect_key(game);
	put_sprite_img(game, game->object.player.direction);
	game->flag.move = TRUE;
}

void	move_south(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (-1 < game->object.player.x - 1
		&& game->map.coordinate[y][x - 1] != WALL)
	{
		--game->object.player.x;
		game->object.player.direction = LEFT;
		if (game->flag.scene == GAME_PLAYING)
			++game->object.player.step.count;
	}
	reflect_key(game);
	put_sprite_img(game, game->object.player.direction);
	game->flag.move = TRUE;
}

void	move_east(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (x + 1 < game->map.cols
		&& game->map.coordinate[y][x + 1] != WALL)
	{
		++game->object.player.x;
		game->object.player.direction = RIGHT;
		if (game->flag.scene == GAME_PLAYING)
			++game->object.player.step.count;
	}
	reflect_key(game);
	put_sprite_img(game, game->object.player.direction);
	game->flag.move = TRUE;
}
