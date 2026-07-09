/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/08 17:13:15 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define MOVE_S 0.06

void	handle_close(t_game *game)
{
	exit_win(game, 0);
}

static int	is_wall(char **map, double x, double y)
{
	int	mx;
	int	my;
	int	rows;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || mx < 0)
		return (1);
	rows = 0;
	while (map[rows])
		rows++;
	if (my >= rows)
		return (1);
	if (mx >= (int)ft_strlen(map[my]))
		return (1);
	if (map[my][mx] == '1' || map[my][mx] == ' ')
		return (1);
	return (0);
}

static void	handle_move(t_game *game, double dx, double dy)
{
	t_player_pos	*pos;
	char			**map;

	pos = &game->maps.p_pos;
	map = game->maps.map;
	if (!is_wall(map, pos->x + dx, pos->y))
		pos->x += dx;
	if (!is_wall(map, pos->x, pos->y + dy))
		pos->y += dy;
	render_walls(&game->player, game->win, &game->maps);
}

static void	handle_rot(t_game *game, double rot)
{
	double	tmp;

	tmp = game->player.dir[0];
	game->player.dir[0] = game->player.dir[0] * cos(rot) - game->player.dir[1]*sin(rot);
	game->player.dir[1] = tmp * sin(rot) + game->player.dir[1] * cos(rot);
	tmp = game->player.plane[0];
    game->player.plane[0] = game->player.plane[0] * cos(rot) - game->player.plane[1] * sin(rot);
    game->player.plane[1] = tmp * sin(rot) + game->player.plane[1] * cos(rot);
	if (!render_walls(&game->player, game->win, &game->maps))
		exit_win(game, -1);
}
 
int	handle_keypress(int keycode, t_game *game)
{
	double dirX;
	double dirY;

	dirX = game->player.dir[0];
	dirY = game->player.dir[1];
	if (keycode == KEY_ESC)
		handle_close(game);
	if (keycode == KEY_W)
		handle_move(game, dirX * MOVE_S, dirY * MOVE_S);
	if (keycode == KEY_S)
		handle_move(game, -dirX * MOVE_S, -dirY * MOVE_S);
	if (keycode == KEY_A)
		handle_move(game, dirY * MOVE_S, -dirX * MOVE_S);
	if (keycode == KEY_D)
		handle_move(game, -dirY * MOVE_S, dirX * MOVE_S);
	if (keycode == KEY_LEFT)
		handle_rot(game, -MOVE_S);
	if (keycode == KEY_RIGHT)
		handle_rot(game, MOVE_S);
	return (0);
}
