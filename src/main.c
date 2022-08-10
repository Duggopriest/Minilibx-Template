#include "../includes/header.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	keypress(int key_id, void	*your_var)
{
	printf("key pressed id is = %d\n", key_id);
	if (key_id == 65307 || key_id == 53)
		exit(1);//exits game

	your_var = NULL; // ignore this
	
	return (0);
}

int	render_next_frame(void *your_var)
{
	// draw next frame
	your_var = NULL; // ignore this

	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");


	// ========================================================== img
	img.img = mlx_new_image(mlx, 1920, 1080); // makes new img
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); // generates address data

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // draws a pixel to the img at x and y then we put in a hex color

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // draws img to the mlx window and the location to draw it at. here we just draw at top left (0,0)

	// ========================================================== keyboard input
	void	*your_var = NULL; // this can be what ever you want. struct recommended 
	mlx_key_hook(mlx_win, keypress, your_var);

	// ========================================================== makes mlx loop over to draw new frames
	//void	*your_var; this can be what ever you want. struct recommended 
	mlx_loop_hook(mlx, render_next_frame, your_var);

	mlx_loop(mlx);
}