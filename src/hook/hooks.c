/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/08 16:51:33 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define MOVE_SPEED 0.1

int	handle_close(t_game *game)
{
	free_struct(&game->maps);
	exit(0);
	return (0);
}

static void	handle_move(t_game *game, double dx, double dy)
{
	(&game->maps)->p_pos.x += dx;
	(&game->maps)->p_pos.y += dy;
	render_walls(&game->player, game->win, &game->maps);
}

static void	handle_rot(t_game *game, double rot)
{
	double		tmp;
	t_player	*p;

	p = &game->player;
	tmp = game->player.dir[0];
	p->dir[0] = p->dir[0] * cos(rot) - p->dir[1] * sin(rot);
	p->dir[1] = tmp * sin(rot) + p->dir[1] * cos(rot);
	tmp = game->player.plane[0];
	p->plane[0] = p->plane[0] * cos(rot) - p->plane[1] * sin(rot);
	p->plane[1] = tmp * sin(rot) + p->plane[1] * cos(rot);
	render_walls(p, game->win, &game->maps);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		handle_close(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		handle_move(game, 0, -0.02);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		handle_move(game, 0, 0.02);
	if (keycode == KEY_A)
		handle_move(game, -0.02, 0);
	if (keycode == KEY_D)
		handle_move(game, 0.02, 0);
	if (keycode == KEY_LEFT)
		handle_rot(game, -0.02);
	if (keycode == KEY_RIGHT)
		handle_rot(game, 0.02);
	return (0);
}
