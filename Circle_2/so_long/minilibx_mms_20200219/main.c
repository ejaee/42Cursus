#include "so_long.h"

void	exit_error(char *error_msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

void	count_total_cols_rows(t_game *game, int fd)
{
	char	buf;
	int	temp_col;

	temp_col = 0;
	game->map_info.cols = 0;
	game->map_info.rows = 0;
	while (read(fd, buf, 1))
	{
		game->map_info.cols++;
		if (buf == '\n')
		{
			game->map_info.rows++;
			// if (game->map_info.cols != temp_col)
			// 	exit_error("error : invaild map");
			temp_col = game->map_info.cols;
			game->map_info.cols = 0;
		}
	}
	game->map_info.cols = temp_col;
}

void	map_create(t_game *game, int fd)
{
	int	idx;

	count_total_cols_rows(game, fd);
	game->map_info.coord_info = (char **)malloc(sizeof(char *) * (game->map_info.cols));
	// malloc fail에 대한 NULL guard가 필요한가?
	idx = -1;
	while (++idx < game->map_info.rows)
		game->map_info.coord_info[idx] = (char *)malloc(sizeof(char) * (game->map_info.rows));
		// malloc fail에 대한 NULL guard가 필요한가?
}

int	is_rectangle(t_game *game, size_t col)
{
	if (game->map_info.cols == col)
		return (TRUE);
	return (FALSE);
}

int	is_vaild_component(t_game *game, char *line)
{
	if (line)
}

void	map_load(t_game *game, char *file_name)
{
	int	fd;
	int	y;
	int	x;
	char *line;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		exit_error("error : file open\n");
	// check line, component & save info into coord.
	// check 1) col size (rectangle)
	// check 2) component (0, 1, C, E, P)
	// save ) info into coord
	// check 3) vaild wall
	y = 0;
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break;
		if (!is_rectangle(game, ft_strlen(line)))
			exit_error("error : invaild map(is not rectangle)\n");
		x = -1;
		while (line[++x])
		{
			if (!is_vaild_component(game, line[x]))
				exit_error("error : invaild map(is not component\n)");
			game->map_info.coord_info[y][x] = line[x];
		}
		y++;
	}
	free(line);


}

void	read_file(t_game *game, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		exit_err("error : file open");
	map_create(game, fd);
	close(fd);
	map_load(game, file_name);


}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error("invalid argc\n");
	read_file(&game, argv[1]);
	game.mlx = mlx_init();

}
