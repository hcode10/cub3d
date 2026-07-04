/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:52:59 by coressor          #+#    #+#             */
/*   Updated: 2026/07/04 20:29:51 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/window.h"

int main()
{
	t_window	*win;
	t_map		map;

	map.floor_color[0] = 123;
	map.floor_color[1] = 155;
	map.floor_color[2] = 16;

	map.sky_color[0] = 164;
	map.sky_color[1] = 123;
	map.sky_color[2] = 98;

	win = init_window(&map);
	if (!win)
	{
		printf("Init window failed");
		return (-1);
	}
	create_back(win);
	draw_back(win);
	mlx_hook(win, 2, 1L << 0, (void *)handle_keypress, &map);
	mlx_hook(win, 17, 0, (void *)handle_close, &map);
	mlx_loop(win->mlx);
	free_window(win);
	return (0);
}
