/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:05:22 by coressor          #+#    #+#             */
/*   Updated: 2026/07/01 09:37:11 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	init_player(t_player *player, t_player_pos *p_pos, char **map)
{
	player->plane[0] = 0;
	player->plane[1] = 0;
	player->dir[0] = 0;
	player->dir[1] = 0;
	if (map[(int)p_pos->y][(int)p_pos->x] == 'N')
	{
		player->dir[0] = 1;
		player->plane[1] = 0.66;
	}
	else if (map[(int)p_pos->y][(int)p_pos->x] == 'S')
	{
		player->dir[0] = -1;
		player->plane[1] = 0.66;
	}
	else if (map[(int)p_pos->y][(int)p_pos->x] == 'E')
	{
		player->dir[1] = 1;
		player->plane[0] = 0.66;
	}
	else if (map[(int)p_pos->y][(int)p_pos->x] == 'W')
	{
		player->dir[1] = -1;
		player->plane[0] = 0.66;
	}
	player->p_pos = p_pos;
}
