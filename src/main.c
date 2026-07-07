/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:45 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/07 20:42:58 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

int	main(int argc, char **argv)
{
	t_game		game;
	
	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
	{
		printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
		return (1);
	}
	parsing(argv[1], &game.maps);
	if (check_before_run(&game.maps))
	{
		//printf("Flood ok !\n");
		// printf("Player position X = %f, Y = %f\n", game.maps->p_pos.x, game.maps->p_pos.y);
		is_map_solvable(&game.maps);
	}

	game.win = init_window(&game.maps);
	if(!game.win)
	{
		printf("Init window failed");
		return (-1);
	}
	int i = 0;
	while ((&game.maps)->map[i])
	{
		for (size_t y = 0; y < ft_strlen((&game.maps)->map[i]); y++)
			printf("%c", (&game.maps)->map[i][y]);
		printf("\n");
		i++;
	}
	init_player(&game.player, &game.maps.p_pos, (&game.maps)->map);
	//mlx_hook(game.win->win, 2, 1L<<0, (void *)handle_keypress, &game);
	// mlx_hook(game.win->win, 2, 1L<<0, (void *)handle_keypress, &game);
	mlx_hook(game.win->win, 2, 1L<<0, (void *)handle_keypress, &game);
	mlx_hook(game.win->win, 17, 0, (void *)handle_close, &game);
	render_walls(&game.player, game.win, &game.maps);
	mlx_loop(game.win->mlx);
	printf("Parsing OK");
	free_struct(&game.maps);
	return (0);
}
