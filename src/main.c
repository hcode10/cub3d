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

int	main(int argc, char **argv)
{
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (error_msg("ex : ./cub3d /path/to/map.cub\n"), -1);
	if (!parsing(argv[1], &game.maps))
		return (error_msg("Parsing fail !\n"), -1);
	if (validate_map_chars(&game.maps))
	{
		if (!is_map_solvable(&game.maps))
			return (free_struct(&game.maps), -1);
	}
	game.win = init_window(&game.maps);
	if (!game.win)
		return (error_msg("Init window failed"), -1);
	init_player(&game.player, &game.maps.p_pos, (&game.maps)->map);
	mlx_hook(game.win->win, 2, 1L << 0, (void *)handle_keypress, &game);
	mlx_hook(game.win->win, 17, 0, (void *)handle_close, &game);
	render_walls(&game.player, game.win, &game.maps);
	mlx_loop(game.win->mlx);
	free_struct(&game.maps);
	return (0);
}
