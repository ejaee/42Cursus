/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:35:43 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 16:54:00 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map.cols * TILE_SIZE;
	height = game->map.rows * TILE_SIZE;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_error("mlx_init() fail\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->win_ptr)
		exit_error("mlx_new_window() fail\n");
}

void	init_player_location(t_game *game)
{
	int	width;
	int	height;

	height = -1;
	while (++height < game->map.rows)
	{
		width = -1;
		while (++width < game->map.cols)
		{
			if (game->map.coordinate[height][width] == PLAYER)
			{
				game->object.player.x = width;
				game->object.player.y = height;
				break ;
			}
		}
	}
}

void	init_collection_count(t_game *game)
{
	int	width;
	int	height;

	game->object.collection.count = 0;
	height = -1;
	while (++height < game->map.rows)
	{
		width = -1;
		while (++width < game->map.cols)
		{
			if (game->map.coordinate[height][width] == COLLECTION)
				++game->object.collection.count;
		}
	}
}

void	init_etc(t_game *game)
{
	game->flag.scene = GAME_PLAYING;
	game->flag.move = FALSE;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_img(game);
	init_player_location(game);
	init_collection_count(game);
	init_etc(game);
}
