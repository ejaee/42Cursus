/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:46:27 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 17:25:22 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_game_scene(t_game *game)
{
	if (game->flag.scene == GAME_ENDING)
		mlx_put_image_to_window \
			(game->mlx_ptr, game->win_ptr, game->object.ending.ptr, 0, 0);
	else
		exit_error("game scene error\n");
}

void	put_game_element(t_game *game)
{
	int	width;
	int	height;

	height = -1;
	while (++height < game->map.rows)
	{
		width = -1;
		while (++width < game->map.cols)
		{
			put_fixed_object(game, width, height);
			put_unfixed_object \
				(game, width, height, game->object.player.direction);
		}
	}
}

int	put_img(t_game *game)
{
	if (game->flag.scene == GAME_ENDING)
		put_game_scene(game);
	else
		put_game_element(game);
	return (0);
}
