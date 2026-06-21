/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   game.c                                             :+:      :+:    :+:   */
=======
/*   init_game.c                                        :+:      :+:    :+:   */
>>>>>>> b336579 (merging dev)
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:05:22 by coressor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/21 14:45:03 by coressor         ###   ########.fr       */
=======
/*   Updated: 2026/06/16 11:59:55 by coressor         ###   ########.fr       */
>>>>>>> b336579 (merging dev)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

<<<<<<< HEAD
void	init_player(t_player *player, t_player_pos *p_pos, char **map)
{
	if (map[(int)p_pos->x][(int)p_pos->y] == 'N')
		player->dir[1] = 1;
	else if (map[(int)p_pos->x][(int)p_pos->y] == 'S')
		player->dir[1] = -1;
	else if (map[(int)p_pos->x][(int)p_pos->y] == 'E')
		player->dir[0] = 1;
	else if (map[(int)p_pos->x][(int)p_pos->y] == 'W')
		player->dir[0] = -1;
	player->plane[0] = p_pos->x * -1;
	player->plane[1] = p_pos->y;
	player->p_pos = p_pos;
=======
void init_player(t_player *player, t_player_pos *p_pos, int dirX, int dirY)
{
	player->dir[0] = dirX;
	player->dir[1] = dirY;
	player->plane[0] = dirY * -1;
	player->plane[1] = dirX;
	player->p_pos = p_pos;	
>>>>>>> b336579 (merging dev)
}
