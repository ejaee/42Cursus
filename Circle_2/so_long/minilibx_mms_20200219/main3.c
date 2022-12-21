#include "main3.h"

void	exit_error(char *error_msg)
{
	ft_putstr_fd(RED "Error\n" RESET, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

void check_extension(char *file) {

	if (!ft_strncmp(file + (ft_strlen(file) - 4 - 1), ".ber", 4))
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

void read_map_size(char *file, t_map *map_info) {
	
	int		fd;
	char	*line;

	map_info->rows = 0;
	fd = open_file(file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map_info->cols = ft_strlen(line) - 1;
		map_info->rows++;
		free(line);
		printf("cols : %d\n", map_info->cols);
	}
	printf("rows : %d\n", map_info->rows);
	// free(line);
	close(fd);
}

void malloc_map(t_map *map_info) {
	int i;

	map_info->coordinate = (char **)malloc(sizeof(char *) * map_info->rows);
	if (!map_info->coordinate)
		exit_error("dynamic allocation fault\n");
	i = -1;
	while (++i < map_info->rows)
		map_info->coordinate[i] = (char *)malloc(sizeof(char *) * map_info->cols);
}

int check_map_component(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == 'R')
		return (TRUE);
	return (FALSE);
}

void check_map_ractangular(t_map *map_info, int len) 
{
	if (map_info->cols != len - 1) 
	{
		printf("length : %d\n", len);
		exit_error("map is not ractangular\n");
	}
}

void load_map(char *file, t_map *map_info) {
	int	i;
	int	j;
	int	fd;
	char *line;

	fd = open_file(file);
	i = 0;
	while (i < map_info->cols)
	{
		
		line = get_next_line(fd);
		// printf("\033[0;31mprintf : %s\n\033[0m", line);
		if (!line)
			break;
		check_map_ractangular(map_info, ft_strlen(line));
		j = -1;
		while (++j < ft_strlen(line) - 1)
		{
			if (check_map_component(line[j]))
				map_info->coordinate[i][j] = line[j];
			else
				exit_error("invalid components found in map\n");
		}
		++i;
		free(line);
	}
	// free(line);
	close(fd);
}

void read_map(char *file, t_map *map_info) {

	read_map_size(file, map_info);
	malloc_map(map_info);
	load_map(file, map_info);
}

void is_valid_wall(t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->rows)
		if (map_info->coordinate[i][0] != '1' || map_info->coordinate[i][map_info->cols - 1] != '1')
			exit_error("invalid wall found in map\n");
	i = -1;
	while (++i < map_info->cols)
		if (map_info->coordinate[0][i] != '1' || map_info->coordinate[map_info->rows - 1][i] != '1')
			exit_error("invalid wall found in map\n");
	
}

void is_contained_essential_elements(t_map *map_info)
{
	int	i;
	int	j;
	int e_flag;
	int p_flag;

	i = -1;
	e_flag = FALSE;
	p_flag = FALSE;
	while (++i < map_info->rows)
	{
		j = -1;
		while (++j < map_info->cols)
		{
			if (map_info->coordinate[i][j] == 'E')
				e_flag = TRUE;
			else if (map_info->coordinate[i][j] == 'P')
				p_flag = TRUE;
		}
	}
	if (!e_flag || !p_flag)
		exit_error("map is not contained essential element");
}

void	check_escape(t_map *map_info, int i, int j)
{
	if (map_info->coordinate[i - 1][j] == '1'
		&& map_info->coordinate[i][j - 1] == '1'
		&& map_info->coordinate[i + 1][j] == '1'
		&& map_info->coordinate[i][j + 1] == '1')
		exit_error("map is not possible to escape");
}

void	is_possible_to_escape(t_map *map_info)
{
	int	i;
	int	j;
	int e_flag;
	int p_flag;

	i = -1;
	e_flag = FALSE;
	p_flag = FALSE;
	while (++i < map_info->rows)
	{
		j = -1;
		while (++j < map_info->cols)
		{
			if (map_info->coordinate[i][j] == 'E')
				check_escape(map_info, i, j);
				
			else if (map_info->coordinate[i][j] == 'P')
				check_escape(map_info, i, j);
		}
	}
}

void parse_loaded_map(t_map *map_info) {
	is_valid_wall(map_info);
	printf("valid_wall!\n");
	is_contained_essential_elements(map_info);
	printf("valid_elements!\n");
	is_possible_to_escape(map_info);
	printf("possible to escape!\n");

}

void print_loaded_map(t_map *map_info)
{
	for (int i = 0; i < map_info->rows; ++i) {
		for (int j = 0; j < map_info->cols; ++j) {
			printf("%c", map_info->coordinate[i][j]);
		}
		printf("\n");
	}
}

int main(int ac, char **av) {
	t_map map_info;
    
	if (ac != 2)
		exit_error("invalid argc");
	check_file(av[1]);
	read_map(av[1], &map_info);
	parse_loaded_map(&map_info);

	print_loaded_map(&map_info);
}