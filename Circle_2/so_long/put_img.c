/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:46:27 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/23 22:10:56 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_game_scene(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (game->flag.scene == GAME_STARTING)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.opening_scene.ptr, 0, 0);
	else if (game->flag.scene == GAME_ENDING)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.ending_scene.ptr, 0, 0);
	else
		exit_error("game scene error\n");
}

void	put_game_element(t_game *game)
{
	int width;
	int height;

	height = -1;
	while (++height < game->map.rows)
	{
		width = -1;
		while (++width < game->map.cols)
		{
			put_fixed_object(game, width, height);
			put_unfixed_object(game, width, height, game->object.player.direction);
		}
	}
}

void	put_step_count(t_game *game)
{
	char	*str;
	int count = game->object.player.step.count;

	str = ft_itoa(count);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 24, 36, 0x000000, str);
	free(str);
}

void	put_kill(t_game *game)
{
	if (game->flag.kill)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.kill_scene.ptr, 0, 0);
}

int	put_img(t_game *game)
{
	if (game->flag.scene == GAME_STARTING || game->flag.scene == GAME_ENDING)
		put_game_scene(game);
	else
	{
		put_game_element(game);
		put_step_count(game);
		put_kill(game);
	}
	return (0);
}
