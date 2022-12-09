#include "../includes/header.h"

void    draw_pixel_demo(t_container *container)
{
    // to draw a pixel we need to create a img first
    // then we draw the pixel to that img
    // then draw that img to the window
    t_data	img;

    // because container in this context is a pointer, insted of '.' we use '->'
    //                               V
    img.img = mlx_new_image(container->mlx, 100, 100); // makes new img 100 x 100 pixels big
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); // generates address data

    // draws a red pixel to the img at x and y then we put in a hex color
	pixel_put(&img, 5, 5, 0x00FF0000); 
    //                    /\
    // its easy to think of this as RGB where FF = 255
    // so it would look like this 0x00RRGGBB

    // draws img to the mlx window and the location to draw it. here we just draw at top left (0,0)
	mlx_put_image_to_window(container->mlx, container->mlx_win, img.img, 0, 0); 
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
