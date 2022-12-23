/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:44:35 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/23 11:45:48 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_file_size(char *file, t_game *game)
{
	int		fd;
	char	*line;

	game->map.rows = 0;
	fd = open_file(file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		game->map.cols = ft_strlen(line) - 1;
		game->map.rows++;
		free(line);
	}
	close(fd);
}

void malloc_map_size(t_game *game)
{
	int i;

	game->map.coordinate = (char **)malloc(sizeof(char *) * game->map.rows);
	if (!game->map.coordinate)
		exit_error("dynamic allocation fault\n");
	i = -1;
	while (++i < game->map.rows)
		game->map.coordinate[i] = (char *)malloc(sizeof(char *) * game->map.cols);
}



void generate_map(char *file, t_game *game)
{
	int	i;
	int	j;
	int	fd;
	char *line;

	fd = open_file(file);
	i = -1;
	while (++i < game->map.cols)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		check_file_ractangular(game, ft_strlen(line));
		j = -1;
		while (++j < ft_strlen(line) - 1)
		{
			if (check_file_component(line[j]))
				game->map.coordinate[i][j] = line[j];
			else
				exit_error("invalid components found in map\n");
		}
		free(line);
	}
	close(fd);
}

void read_file(char *file, t_game *game)
{
	check_file(file);
	get_file_size(file, game);
	malloc_map_size(game);
	generate_map(file, game);
}
