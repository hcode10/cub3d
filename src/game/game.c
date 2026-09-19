/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:05:22 by coressor          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_player(t_player *player, t_player_pos *p_pos, char **map)
{
	char	c;

	player->plane[0] = 0;
	player->plane[1] = 0;
	player->dir[0] = 0;
	player->dir[1] = 0;
	player->p_pos = p_pos;
	c = map[(int)p_pos->y][(int)p_pos->x];
	if (c == 'N' || c == 'S')
	{
		player->dir[1] = 1;
		player->plane[0] = -0.66;
	}
	else
	{
		player->dir[0] = 1;
		player->plane[1] = 0.66;
	}
	if (c == 'N' || c == 'W')
	{
		player->dir[0] *= -1;
		player->dir[1] *= -1;
		player->plane[0] *= -1;
		player->plane[1] *= -1;
	}
}
