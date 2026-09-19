/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:45 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	setup(t_game *game, char *path)
{
	if (!parsing(path, &game->maps))
		return (free_struct(&game->maps), 1);
	if (!validate_map_chars(&game->maps) || !is_map_solvable(&game->maps))
		return (free_struct(&game->maps), 1);
	game->win = init_window(&game->maps);
	if (!game->win)
		return (error_msg("Window: initialisation impossible"),
			free_struct(&game->maps), 1);
	init_player(&game->player, &game->maps.p_pos, game->maps.map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (error_msg("Usage: ./cub3D chemin/vers/carte.cub"));
	if (setup(&game, argv[1]) != 0)
		return (1);
	mlx_hook(game.win->win, 2, 1L << 0, (void *)handle_keypress, &game);
	mlx_hook(game.win->win, 17, 1L << 17, (void *)handle_close, &game);
	mlx_hook(game.win->win, 12, 1L << 15, (void *)handle_expose, &game);
	if (!render_walls(&game.player, game.win, &game.maps))
	{
		error_msg("Render: impossible de dessiner la scene");
		free_struct(&game.maps);
		free_window(game.win);
		return (1);
	}
	mlx_loop(game.win->mlx);
	exit_win(&game, 0);
	return (0);
}
