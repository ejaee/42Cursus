/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:48:42 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 13:49:31 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	exit_error(char *error_msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

int	open_file(char *file)
{
	int	fd;

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
	int		i;
	int		x;
	int		y;
	void	*img_ptr;

	x = game->object.player.x;
	y = game->object.player.y;
	img_ptr = game->object.player.img[direction][1].ptr;
	put_fixed_object(game, x, y);
	i = -1;
	while (++i < 1000)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
	img_ptr = game->object.player.img[direction][2].ptr;
	put_fixed_object(game, game->object.player.x, game->object.player.y);
	i = -1;
	while (++i < 1000)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}
