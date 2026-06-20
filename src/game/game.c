/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:05:22 by coressor          #+#    #+#             */
/*   Updated: 2026/06/16 11:59:55 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void init_player(t_player *player, t_player_pos *p_pos, int dirX, int dirY)
{
	player->dir[0] = dirX;
	player->dir[1] = dirY;
	player->plane[0] = dirY * -1;
	player->plane[1] = dirX;
	player->p_pos = p_pos;	
}
