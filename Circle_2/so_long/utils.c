/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:48:42 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/23 22:13:55 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error_msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

int	open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit_error("fail file open\n");
	return (fd);

}

void	show_step_count(int count)
{
	ft_putstr_fd("Step : ", 1);
	ft_putnbr_fd(count, 1);
	ft_putstr_fd("\n", 1);
}

void	put_sprite_img(t_game *game, int direction)
{
	int i;

	put_fixed_object(game, game->object.player.x, game->object.player.y);
	i = -1;
	while (++i < 1000)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.player.img[direction][1].ptr, game->object.player.x * TILE_SIZE, game->object.player.y * TILE_SIZE);
	}
	put_fixed_object(game, game->object.player.x, game->object.player.y);
	i = -1;
	while (++i < 1000)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.player.img[direction][2].ptr, game->object.player.x * TILE_SIZE, game->object.player.y * TILE_SIZE);
	}
}
