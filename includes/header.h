#ifndef HEADER_H
# define HEADER_H

# include "../minilibx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_container
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
} t_container;

// pixel_draw
void    draw_pixel_demo(t_container *container);
void	pixel_put(t_data *data, int x, int y, int color);

// import_img
void    import_img_demo(t_container *container);

// key_press
int		key_press(int key_id, t_container *container);

// mouse_press
void    mouse_demo(t_container *container);
int 	mouse_press(int button, int x, int y, t_container *container);

#endif