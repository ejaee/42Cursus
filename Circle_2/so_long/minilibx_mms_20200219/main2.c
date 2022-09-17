#include "mlx.h"
#include <stdlib.h>

typedef struct	s_vars {
	void		*mlx_ptr;
	void		*win_ptr;
}				t_vars;

// struct image data
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// memory를 y 와 x의 값을 통해 이동 후 color 값을 입력
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// esc를 눌렀을때 종료
int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}

void	print_image()
{
	int	color;
	t_vars	vars;
	t_data	image;

	int	img_width = 1920;
	int	img_height = 1080;

	int	trgb;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, img_width, img_height, "so_long 42");
	image.img = mlx_new_image(vars.mlx_ptr, img_width, img_height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	for (int i = 0; i < img_height - 1; ++i)
	{
		for(int j = 0; j < img_width - 1; ++j)
		{
			double	r = (double)(img_width - j) / (img_width - 1);
			double	g = (double)(i) / (img_height
			 - 1);
			double	b = 1;
			color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));

			my_mlx_pixel_put(&image, j, i, color);
		}
	}
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, image.img, 0, 0);
	mlx_key_hook(vars.win_ptr, key_hook, &vars); // esc key press event
	mlx_hook(vars.win_ptr, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx_ptr);
}

int	main()
{
	print_image();
	return (0);
}
