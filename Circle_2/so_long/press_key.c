/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:42:15 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/23 21:32:54 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_direction(t_game *game, int direction)
{
	game->flag.kill = FALSE;
	if (direction == NORTH)
		move_north(game);
	else if (direction == WEST)
		move_west(game);
	else if (direction == SOUTH)
		move_south(game);
	else if (direction == EAST)
		move_east(game);

}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_R && game->flag.scene == GAME_STARTING)
		game->flag.scene = GAME_PLAYING;
	else if (key_code == KEY_W || key_code == KEY_UP)
		move_direction(game, NORTH);
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		move_direction(game, WEST);
	else if (key_code == KEY_A || key_code == KEY_LEFT)
		move_direction(game, SOUTH);
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		move_direction(game, EAST);
	return (0);
}
