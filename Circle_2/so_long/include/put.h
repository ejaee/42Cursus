/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:14:28 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 17:17:22 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

typedef struct s_game	t_game;

void	put_fixed_object(t_game *game, int x, int y);
void	put_unfixed_object(t_game *game, int x, int y, int direction);
void	put_collection(t_game *game, int x, int y);
void	put_exit(t_game *game, int x, int y);
void	put_player(t_game *game, int direction);

void	put_game_scene(t_game *game);
void	put_game_element(t_game *game);
int		put_img(t_game *game);


#endif

