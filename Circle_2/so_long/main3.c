#include "main3.h"

void	exit_error(char *error_msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

void check_extension(char *file) {

	if (!ft_strncmp(file + (ft_strlen(file) - 4 - 1), MAP_EXTENSION, 4))
		exit_error("invalid extension");

}

void check_file(char *file) {

	check_extension(file);
}

int	open_file(char *file) {
	int fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit_error("fail file open\n");
	return (fd);

}

void read_map_size(char *file, t_game *game) {

	int		fd;
	char	*line;

	game->map_info.rows = 0;
	fd = open_file(file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		game->map_info.cols = ft_strlen(line) - 1;
		game->map_info.rows++;
		free(line);
		printf("cols : %d\n", game->map_info.cols);
	}
	printf("rows : %d\n", game->map_info.rows);
	// free(line);
	close(fd);
}

void malloc_map(t_game *game) {
	int i;

	game->map_info.coordinate = (char **)malloc(sizeof(char *) * game->map_info.rows);
	if (!game->map_info.coordinate)
		exit_error("dynamic allocation fault\n");
	i = -1;
	while (++i < game->map_info.rows)
		game->map_info.coordinate[i] = (char *)malloc(sizeof(char *) * game->map_info.cols);
}

int check_map_component(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == 'R')
		return (TRUE);
	return (FALSE);
}

void check_map_ractangular(t_game *game, int len)
{
	if (game->map_info.cols != len - 1)
	{
		printf("length : %d\n", len);
		exit_error("map is not ractangular\n");
	}
}

void load_map(char *file, t_game *game) {
	int	i;
	int	j;
	int	fd;
	char *line;

	fd = open_file(file);
	i = 0;
	while (i < game->map_info.cols)
	{

		line = get_next_line(fd);
		// printf("\033[0;31mprintf : %s\n\033[0m", line);
		if (!line)
			break;
		check_map_ractangular(game, ft_strlen(line));
		j = -1;
		while (++j < ft_strlen(line) - 1)
		{
			if (check_map_component(line[j]))
				game->map_info.coordinate[i][j] = line[j];
			else
				exit_error("invalid components found in map\n");
		}
		++i;
		free(line);
	}
	// free(line);
	close(fd);
}

void read_map(char *file, t_game *game) {

	read_map_size(file, game);
	malloc_map(game);
	load_map(file, game);
}

void is_valid_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_info.rows)
		if (game->map_info.coordinate[i][0] != '1' || game->map_info.coordinate[i][game->map_info.cols - 1] != '1')
			exit_error("invalid wall found in map\n");
	i = -1;
	while (++i < game->map_info.cols)
		if (game->map_info.coordinate[0][i] != '1' || game->map_info.coordinate[game->map_info.rows - 1][i] != '1')
			exit_error("invalid wall found in map\n");

}

void is_contained_essential_elements(t_game *game)
{
	int	i;
	int	j;
	int e_flag;
	int p_flag;

	i = -1;
	e_flag = FALSE;
	p_flag = FALSE;
	while (++i < game->map_info.rows)
	{
		j = -1;
		while (++j < game->map_info.cols)
		{
			if (game->map_info.coordinate[i][j] == 'E')
				e_flag = TRUE;
			else if (game->map_info.coordinate[i][j] == 'P')
				p_flag = TRUE;
		}
	}
	if (!e_flag || !p_flag)
		exit_error("map is not contained essential element");
}

void	check_escape(t_game *game, int i, int j)
{
	if (game->map_info.coordinate[i - 1][j] == '1'
		&& game->map_info.coordinate[i][j - 1] == '1'
		&& game->map_info.coordinate[i + 1][j] == '1'
		&& game->map_info.coordinate[i][j + 1] == '1')
		exit_error("map is not possible to escape");
}

void	is_possible_to_escape(t_game *game)
{
	int	i;
	int	j;
	int e_flag;
	int p_flag;

	i = -1;
	e_flag = FALSE;
	p_flag = FALSE;
	while (++i < game->map_info.rows)
	{
		j = -1;
		while (++j < game->map_info.cols)
		{
			if (game->map_info.coordinate[i][j] == 'E')
				check_escape(game, i, j);

			else if (game->map_info.coordinate[i][j] == 'P')
				check_escape(game, i, j);
		}
	}
}

void parse_loaded_map(t_game *game) {
	is_valid_wall(game);
	printf("valid_wall!\n");
	is_contained_essential_elements(game);
	printf("valid_elements!\n");
	is_possible_to_escape(game);
	printf("possible to escape!\n");

}

void print_loaded_map(t_game *game)
{
	for (int i = 0; i < game->map_info.rows; ++i) {
		for (int j = 0; j < game->map_info.cols; ++j) {
			printf("%c", game->map_info.coordinate[i][j]);
		}
		printf("\n");
	}
}

void	init_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map_info.cols * TILE_SIZE;
	height = game->map_info.rows * TILE_SIZE;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_error("mlx_init() fail\n");

	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->win_ptr)
		exit_error("mlx_new_window() fail\n");

}

void	init_tile_img(t_game *game)
{
	int width;
	int height;

	game->object.opening_scene.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/opening_scene.xpm", &width, &height);
	game->object.tile_0.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/tile_0.xpm", &width, &height);
	game->object.tile_1.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/tile1.xpm", &width, &height);
	game->object.exit_1.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit_1.xpm", &width, &height);
	// game->object.exit_pos.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit0.xpm", &width, &height);
}

void	init_player_img(t_game *game)
{
	int width;
	int height;

	game->object.player.img[RIGHT][0].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/c_r0.xpm", &width, &height);
	game->object.player.img[RIGHT][1].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/c_r1.xpm", &width, &height);
	game->object.player.img[RIGHT][2].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/c_r2.xpm", &width, &height);
	game->object.player.img[LEFT][0].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/c_l0.xpm", &width, &height);
	game->object.player.img[LEFT][1].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/c_l1.xpm", &width, &height);
	game->object.player.img[LEFT][2].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/c_l2.xpm", &width, &height);
}

void	init_collection_img(t_game *game)
{
	int width;
	int height;

	game->object.collection.img[0].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/collection_0.xpm", &width, &height);
	game->object.collection.img[1].ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/collection_1.xpm", &width, &height);
}

void	init_img(t_game *game)
{
	init_tile_img(game);
	init_player_img(game);
	init_collection_img(game);
}

void	init_player_location(t_game *game)
{
	int width;
	int height;

	height = -1;
	while (++height < game->map_info.rows)
	{
		width = -1;
		while (++width < game->map_info.cols)
		{
			if (game->map_info.coordinate[height][width] == 'P')
			{
				game->object.player.x = width;
				game->object.player.y = height;
			}
		}
	}
}

void	init_etc(t_game *game)
{
	game->flag.scene = 0;
}

void init_game(t_game *game)
{
	init_window(game);
	init_img(game);
	init_player_location(game);
	init_etc(game);


}

void	put_animation_img(t_game *game, int direction)
{
	int i;



	i = -1;
	while (++i < 1000)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.player.img[direction][1].ptr, game->object.player.x * TILE_SIZE, game->object.player.y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.player.img[direction][2].ptr, game->object.player.x * TILE_SIZE, game->object.player.y * TILE_SIZE);
	}

}

void	move_north(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (-1 < game->object.player.y - 1
		&& game->map_info.coordinate[y - 1][x] != '1')
		--game->object.player.y;
	put_animation_img(game, game->object.player.direction);

}

void	move_west(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (game->object.player.y + 1 < game->map_info.rows
		&& game->map_info.coordinate[y + 1][x] != '1')
		++game->object.player.y;

	put_animation_img(game, game->object.player.direction);

}

void	move_south(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (-1 < game->object.player.x - 1
		&& game->map_info.coordinate[y][x - 1] != '1')
	{
		--game->object.player.x;
		game->object.player.direction = LEFT;
	}
	put_animation_img(game, game->object.player.direction);

}

void	move_east(t_game *game)
{
	int x;
	int y;

	x = game->object.player.x;
	y = game->object.player.y;
	if (game->object.player.x + 1 < game->map_info.cols
		&& game->map_info.coordinate[y][x + 1] != '1')
	{
		++game->object.player.x;
		game->object.player.direction = RIGHT;
	}

	put_animation_img(game, game->object.player.direction);

}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_north(game);
	if (key_code == KEY_S)
		move_west(game);
	if (key_code == KEY_A)
		move_south(game);
	if (key_code == KEY_D)
		move_east(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

void	show_game_scene(t_game *game)
{
	int		x;
	int		y;

	x = game->map_info.cols / 2 - 2;
	y = game->map_info.rows / 2 - 2;
	printf("(%d, %d)\n",x, y);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (game->flag.scene == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.opening_scene.ptr, x, y);
	// else if (game->flag.game_scene == GAME_OVER)
	// 	ft_put_img64(game, game->gameover.ptr, x, y);
	// else if (game->flag.game_scene == GAME_ENDING)
	// {
	// 	_draw_ending_pika(game);
	// 	ft_put_img64(game, game->ending.ptr, x, y);
	// }
	// else
	// 	exit_err("GAME SCENE ERROR\n");
}

int	put_img(t_game *game)
{
	int width;
	int height;
	int is_dead;
	int direction;

	if (!game->flag.scene)
	{
		show_game_scene(game);
	}
	else
	{
		height = -1;
		is_dead = 0;
		while (++height < game->map_info.rows)
		{
			width = -1;
			while (++width < game->map_info.cols)
			{
				if (game->map_info.coordinate[height][width] == '1')
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.tile_1.ptr, width * TILE_SIZE, height * TILE_SIZE);
				else if	(game->map_info.coordinate[height][width] == 'E')
				{
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.tile_0.ptr, width * TILE_SIZE, height * TILE_SIZE);
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.exit_1.ptr, width * TILE_SIZE, height * TILE_SIZE);
				}
				else
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.tile_0.ptr, width * TILE_SIZE, height * TILE_SIZE);
				if (game->map_info.coordinate[height][width] == 'C')
				{
					if (game->object.player.x == width && game->object.player.y == height)
					game->map_info.coordinate[height][width] = DEAD;
						mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.collection.img[0].ptr, width * TILE_SIZE, height * TILE_SIZE);
				}
				if (game->map_info.coordinate[height][width] == DEAD)
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.collection.img[1].ptr, width * TILE_SIZE, height * TILE_SIZE);
				direction = game->object.player.direction;

				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->object.player.img[direction][0].ptr, game->object.player.x * TILE_SIZE, game->object.player.y * TILE_SIZE);
			}

		}
	}


	return (0);
}

int	main(int ac, char **av) {
	t_game game;

	if (ac != 2)
		exit_error("invalid argc");

	check_file(av[1]);

	read_map(av[1], &game);

	parse_loaded_map(&game);
	print_loaded_map(&game);

	init_game(&game);

	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, press_key, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, close_game, &game);
	mlx_loop_hook(game.mlx_ptr, &put_img, &game);

	mlx_loop(game.mlx_ptr);
}
