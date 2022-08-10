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

#endif