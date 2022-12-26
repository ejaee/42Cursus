/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:43:25 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 13:49:01 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	check_file_ractangular(t_game *game, int len)
{
	if (game->map.cols != len - 1)
		exit_error("map is not ractangular\n");
}

int	check_file_component(char c)
{
	if (c == EMPTY || c == WALL || c == COLLECTION
		|| c == PLAYER || c == EXIT)
		return (TRUE);
	return (FALSE);
}

void	check_extension(char *file)
{
	if (!ft_strncmp(file + (ft_strlen(file) - 4 - 1), FILE_EXTENSION, 4))
		exit_error("invalid extension\n");
}

void	check_file(char *file)
{
	check_extension(file);
}
