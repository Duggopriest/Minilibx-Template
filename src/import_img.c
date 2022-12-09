#include "../includes/header.h"

void    import_img_demo(t_container *container)
{
    int	w;
	int	h;	
														// V location	    V   V here we give it the address of two ints and it will edit them with the width and hight of the imported img
	container->img = mlx_xpm_file_to_image(container->mlx, "img/frog.xpm", &w, &h);
	// because container in this context is a pointer, insted of '.' we use '->'

	// no need to grab address data
	
	// draws img to the mlx window and the location of where to draw it(50,50)
	mlx_put_image_to_window(container->mlx, container->mlx_win, container->img, 50, 50); // draws img to the mlx window and the location to draw it at. here we just draw at top left (0,0)
}
