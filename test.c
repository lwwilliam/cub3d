#include <stdio.h>
// #include <mlx.h>

// int main(void)
// {
// 	void *mlx;
// 	void *img;
// 	char *img_addr;
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;

// 	// Initialize mlx and create an image
// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);

// 	// Get the data address and image characteristics
// 	img_addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

// 	// Print the image characteristics
// 	printf("Bits per pixel: %d\n", bits_per_pixel);
// 	printf("Line length: %d\n", line_length);
// 	printf("Endian: %d\n", endian);

// 	return 0;
// }

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;
	t_data	img;

	i = 100;
	j = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (i < 200)
	{
		j = 100;
		while (j < 200)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}