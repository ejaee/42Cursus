#include "so_long.h"

void	exit_error(char *error_msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

void	count_total_cols_rows(t_game *game, int fd)
{
	char	c;
	int		temp_row;

	game->map_info.cols = 0;
	game->map_info.rows = 0;
	temp_row = 0;
	while (read(fd, &c, 1))
	{
		if (game->map_info.rows < temp_row)
			game->map_info.rows = temp_row;
		if (c == '\n')
		{
			game->map_info.cols++;
			temp_row = 0;
		}
		else
			temp_row++;
	}
}

void	map_create(t_game *game, int fd)
{
	int	idx;

	count_total_cols_rows(game, fd);
	game->map_info.coord = (char **)malloc(sizeof(char *) * (game->map_info.cols));
	// malloc fail에 대한 NULL guard가 필요한가?
	idx = -1;
	while (++idx < game->map_info.cols)
		game->map_info.coord[idx] = (char *)malloc(sizeof(char) * (game->map_info.rows));
		// malloc fail에 대한 NULL guard가 필요한가?
}

int	is_rectangle(t_game *game, size_t x)
{
	if (game->map_info.rows == x)
		return (TRUE);
	return (FALSE);
}

int	is_component(t_game *game, char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (TRUE);
	return (FALSE);
}

int	is_walled(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_info.cols)
	{
		if (!(game->map_info.coord[y][0] == '1' && game->map_info.coord[y][game->map_info.rows - 1] == '1'))
			return (FALSE);
	}
	x = -1;
	while (++x < game->map_info.rows)
	{
		if (!(game->map_info.coord[0][x] == '1' && game->map_info.coord[game->map_info.cols - 1][x] == '1'))
			return (FALSE);
	}
	return (TRUE);
}

void	cnt_component(t_game *game, char c)
{
	if (c == 'c')
		game->map_info.component.collect++;
	else if (c == 'e')
		game->map_info.component.exit++;
	else if (c == 'p')
		game->map_info.component.player++;
}

void	map_load(t_game *game, char *file_name)
{
	int	fd;
	int	y;
	int	x;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		exit_error("issue : file open\n");
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!is_rectangle(game, ft_strlen(line) - 1))
			exit_error("issue : invaild map (is not rectangle)\n");
		x = -1;
		while (line[++x] && line[x] != '\n')
			if (!is_component(game, line[x]))
				exit_error("issue : invaild map (is not component)\n");
			game->map_info.coord[y][x] = line[x];
		y++;
	}
	free(line);
	close(fd);
}

void	read_file(t_game *game, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		exit_error("issue : file open\n");
	map_create(game, fd);
	close(fd);
	map_load(game, file_name);
	if (!is_walled(game))
		exit_error("issue : invaild map (is invaild wall)\n");
	// count component && check vaildate component number
	if (!check_component_count())
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error("invalid argc\n");

	read_file(&game, argv[1]);
	printf(BLUE "vaild map!\n" RESET);
	// game.mlx = mlx_init();
}
