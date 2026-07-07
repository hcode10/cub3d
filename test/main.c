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
#include "../minilibx-linux/mlx.h"

// int	init_map(t_map *m)
// {
// 	char	*grid[] = {
// 		"1111111111111111",
// 		"1000000000000001",
// 		"1000000000000001",
// 		"1001111000000001",
// 		"1001000000000001",
// 		"1001000000N00001",
// 		"1001000001111001",
// 		"1000000001000001",
// 		"1000000001000001",
// 		"1000000000000001",
// 		"1111111111111111",
// 		NULL
// 	};
//
// 	m->map = dup_grid(grid);
// 	m->map_dup = dup_grid(grid);
// 	if (!m->map || !m->map_dup || !init_textures(m))
// 		return (0);
// 	init_colors_and_pos(m);
// 	return (1);
// }

int	end_loop(void *mlx)
{
	mlx_loop_end(mlx);
	return (1);
}
int key_hook(void *mlx)
{
	mlx_loop_end(mlx);
    return (0);
}
int end(int keycode, void *param)
{
	(void) keycode;
	fflush(stdout);
	printf("salut");
	(void) param;
	// (void) win;
	// printf("slaut\n");
	return (1);
}

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
	create_back(win, &win->img);;
	draw_back(win);
	mlx_hook(win, 2, 1L << 0, (void *)handle_keypress, &map);
	mlx_hook(win, 17, 0, (void *)handle_close, &map);
	mlx_loop(win->mlx);
	free_window(win);
	return (0);
}
