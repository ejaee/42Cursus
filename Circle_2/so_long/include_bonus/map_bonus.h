/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:52:39 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 13:50:41 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coordinate;
}	t_map;

typedef struct s_game	t_game;

void	is_valid_wall(t_game *game);
void	is_contained_essential_elements(t_game *game);
void	check_surrounded(t_game *game, int i, int j);
void	is_it_surrounded(t_game *game);
void	parse_map(t_game *game);

void	init_window(t_game *game);
void	init_player_location(t_game *game);
void	init_collection_count(t_game *game);
void	init_etc(t_game *game);
void	init_game(t_game *game);

#endif
