#include "../includes/header.h"

int	key_press(int key_id, t_container *container)
{
	printf("key pressed id is = %d\n", key_id);
    //   linux esc V        mac esc  V
	if (key_id == 65307 || key_id == 53)
		exit(1);//exits game
	
	return (0);
}