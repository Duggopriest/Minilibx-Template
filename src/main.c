#include "../includes/header.h"

int	render_next_frame(t_container *container)
{
	(void)container; // ignore this

	// this will be your main loop for what goes on every frame of the program
	
	return (0);
}

int	main(void)
{
	t_container container; // this is a struct we use to hold all the variables that we use. this makes it easier to assess vars from multiable places

	// we initlise mlx and create a window setting the size and name
	container.mlx = mlx_init();
	container.mlx_win = mlx_new_window(container.mlx, 1920, 1080, "Hello world!");

	// ========================== demos ===================================

	// drawing pixels
	draw_pixel_demo(&container);

	// importting images
	import_img_demo(&container);

	// keyboard input
	// 							 		v this function everytime you press a key
	mlx_key_hook(container.mlx_win, key_press, &container);

	// mouse input
	// 							 		v this function everytime you press a button on the mouse
	mlx_mouse_hook(container.mlx, mouse_press, &container);

	// =====================================================================

	// 				this will run 		v this function every frame
	mlx_loop_hook(container.mlx, render_next_frame, &container);

	mlx_loop(container.mlx); // this keeps the window open
}