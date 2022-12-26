/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:46:06 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 13:50:25 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_BONUS_H
# define FILE_BONUS_H

# define FILE_EXTENSION ".ber"

typedef struct s_game	t_game;

void	check_file_ractangular(t_game *game, int len);
int		check_file_component(char c);
void	check_extension(char *file);
void	check_file(char *file);

void	get_file_size(char *file, t_game *game);
void	malloc_map_size(t_game *game);
void	generate_map(char *file, t_game *game);
void	read_file(char *file, t_game *game);

#endif
