#include "../includes/header.h"

void    mouse_demo(t_container *container)
{
    int x;
    int y;

    // this function will grab the pos of the mouse relitive to the 0,0 of the window
    //                                      V  here we give it two int addresses and it will edit them acording to the mouse pos
    mlx_mouse_get_pos(container->mlx_win, &x, &y);
}

int    mouse_press(int button, int x, int y, t_container *container)
{
    printf("mouse x(%d) y(%d) button(%d)\n", x, y, button);
    return (0);
}