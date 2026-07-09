/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:45 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/08 16:11:23 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// static bool	check_before_run(t_map *game)
// {
// 	;
// 	return (true);
// }

int	main(int argc, char **argv)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (printf("Arguments incorrect : ./cub3d /path/to/map.cub\n"), 1);
	if (!parsing(argv[1], &game.maps) || !validate_map_chars(&game.maps) 
		|| !is_map_solvable(&game.maps))
			return (-1);
	game.win = init_window(&game.maps);
	if(!game.win)
		return (printf("Init window failed"), -1);
	init_player(&game.player, &game.maps.p_pos, (&game.maps)->map);
	mlx_hook(game.win->win, 2, 1L << 0, (void *)handle_keypress, &game);
	mlx_hook(game.win->win, 17, 0, (void *)handle_close, &game);
	if (!render_walls(&game.player, game.win, &game.maps))
		return (printf("Error:\n reder walls"), -1);
	mlx_loop(game.win->mlx);
	free_struct(&game.maps);
	free_window(game.win);
	return (0);
}
