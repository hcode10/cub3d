/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:45 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/03 18:00:37 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../includes/window.h"
#include "../includes/game.h"

/*static int	validate_map(t_map *game)
{
	if (!validate_map_chars(game))
	{
		return (-1);
	}
	if (is_map_solvable(game) == -1)
		return (-1);
	return (0);
}*/

static bool	check_before_run(t_map *game)
{
	validate_map_chars(game);
	return (true);
}

int main(int argc, char **argv)
{
	t_map		map;
	t_window	*win;
	t_player	player;

	ft_bzero(&map, sizeof(t_map));
	t_map *map;
	if (argc != 2)
	{
		printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
		return (1);
	}
	parsing(argv[1], &map);
	if (check_before_run(&map))
	{
		//printf("Flood ok !\n");
		printf("Player position X = %f, Y = %f\n", map.p_pos.x, map.p_pos.y);
		is_map_solvable(&map);
	}

	win = init_window(&map);
	if(!win)
	{
		printf("Init window failed");
		return (-1);
	}
	int i = 0;
	while (map.map[i])
	{
		for (size_t y = 0; y < ft_strlen(map.map[i]); y++)
			printf("%c", map.map[i][y]);
		printf("\n");
		i++;
	}
	printf("%d %d\n", (int)map.p_pos.x, (int)map.p_pos.y); 
	printf("\n\n\n\n\n%c\n\n\n\n", map.map[11][26]);
	// printf("\n\n\n\n\n\n%c\n\n\n\n\n\n\n", map.map[(int)map.p_pos.x][(int)map.p_pos.y]);
	init_player(&player, &map.p_pos, map.map);
// if (!create_back(win, &win->img))
	// 	printf("Fail to create back");
	// if (!draw_back(win))
	// 	printf("Fail to draw");
	// mlx_hook(win->win, 17, (1L << 5), (void *)key_hook, win->mlx);  // d'abord
	render_walls(&player, win, &map);
	mlx_loop(win->mlx);
	printf("Parsing OK");
	free_struct(&map);
	{
		printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
		return (1);
	}
<<<<<<< HEAD
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	parsing(argv[1], map);
=======
	if (!parsing(argv[1], &map))
	{
		printf("Erreur de parsing !\n");
		free_struct(&map);
		return (1);
	}
	printf("Parsing OK");
	free_struct(&map);
>>>>>>> a44602a (Feat : Parsing)
	return (0);
}
