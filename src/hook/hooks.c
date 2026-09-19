/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	handle_close(t_game *game)
{
	exit_win(game, 0);
	return (0);
}

int	handle_expose(t_game *game)
{
	if (!render_walls(&game->player, game->win, &game->maps))
		exit_win(game, 1);
	return (0);
}

static void	handle_move(t_game *game, double dx, double dy)
{
	t_player_pos	*pos;
	char			**map;
	double			mx;
	double			my;

	pos = &game->maps.p_pos;
	map = game->maps.map;
	mx = pos->x + dx + HITBOX * (dx > 0) - HITBOX * (dx < 0);
	my = pos->y + dy + HITBOX * (dy > 0) - HITBOX * (dy < 0);
	if (!is_wall(map, mx, pos->y))
		pos->x += dx;
	if (!is_wall(map, pos->x, my))
		pos->y += dy;
	if (!render_walls(&game->player, game->win, &game->maps))
		exit_win(game, 1);
}

static void	handle_rot(t_game *game, double rot)
{
	t_player	*p;
	double		tmp;

	p = &game->player;
	tmp = p->dir[0];
	p->dir[0] = p->dir[0] * cos(rot) - p->dir[1] * sin(rot);
	p->dir[1] = tmp * sin(rot) + p->dir[1] * cos(rot);
	tmp = p->plane[0];
	p->plane[0] = p->plane[0] * cos(rot) - p->plane[1] * sin(rot);
	p->plane[1] = tmp * sin(rot) + p->plane[1] * cos(rot);
	if (!render_walls(&game->player, game->win, &game->maps))
		exit_win(game, 1);
}

int	handle_keypress(int keycode, t_game *game)
{
	double	dir_x;
	double	dir_y;

	dir_x = game->player.dir[0];
	dir_y = game->player.dir[1];
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		handle_move(game, dir_x * MOVE_S, dir_y * MOVE_S);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		handle_move(game, -dir_x * MOVE_S, -dir_y * MOVE_S);
	else if (keycode == KEY_A)
		handle_move(game, dir_y * MOVE_S, -dir_x * MOVE_S);
	else if (keycode == KEY_D)
		handle_move(game, -dir_y * MOVE_S, dir_x * MOVE_S);
	else if (keycode == KEY_LEFT)
		handle_rot(game, -ROT_S);
	else if (keycode == KEY_RIGHT)
		handle_rot(game, ROT_S);
	return (0);
}
