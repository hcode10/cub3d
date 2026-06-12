#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../includes/window.h"

int main()
{
 	t_window *win;

	win = init_window();
	if(!win)
	{
		printf("Init window failed");
		return (-1);
	}
	mlx_loop(win->mlx);
	free_window(win);
	return (0);
}  
