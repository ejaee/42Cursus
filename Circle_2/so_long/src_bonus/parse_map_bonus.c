/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:57:31 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 20:16:50 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	is_valid_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.rows)
		if (game->map.coordinate[i][0] != WALL
			|| game->map.coordinate[i][game->map.cols - 1] != WALL)
			exit_error("invalid wall found in map\n");
	i = -1;
	while (++i < game->map.cols)
		if (game->map.coordinate[0][i] != WALL
			|| game->map.coordinate[game->map.rows - 1][i] != WALL)
			exit_error("invalid wall found in map\n");
}

void	is_contained_essential_elements(t_game *game)
{
	int	i;
	int	j;

	game->flag.player = FALSE;
	game->flag.exit = FALSE;
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.coordinate[i][j] == EXIT)
				++game->flag.exit;
			else if (game->map.coordinate[i][j] == PLAYER)
				++game->flag.player;
		}
	}
	if (game->flag.player != TRUE || game->flag.exit != TRUE)
		exit_error("map is not contained essential element");
}

void	check_surrounded(t_game *game, int i, int j)
{
	if (game->map.coordinate[i - 1][j] == WALL
		&& game->map.coordinate[i][j - 1] == WALL
		&& game->map.coordinate[i + 1][j] == WALL
		&& game->map.coordinate[i][j + 1] == WALL)
		exit_error("map is not possible to escape");
}

void	is_it_surrounded(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.coordinate[i][j] == EXIT)
				check_surrounded(game, i, j);
			else if (game->map.coordinate[i][j] == PLAYER)
				check_surrounded(game, i, j);
		}
	}
}

void	parse_map(t_game *game)
{
	is_valid_wall(game);
	is_contained_essential_elements(game);
	is_it_surrounded(game);
}
