/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/04 20:51:08 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "window.h"
#include "mlx.h"

int	handle_close(t_map *map)
{
	free_struct(map);
	exit(0);
	return (0);
}

static void	handle_move(t_map *map, int dx, int dy)
{
	(void)map;
	(void)dx;
	(void)dy;
	/*int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	move_player(game, new_x, new_y);*/
	printf("hook handle_move");
}

int	handle_keypress(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		handle_close(map);
	else if (keycode == KEY_W || keycode == KEY_UP)
		handle_move(map, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		handle_move(map, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		handle_move(map, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		handle_move(map, 1, 0);
	return (0);
}
