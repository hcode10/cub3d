/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:51:47 by coressor          #+#    #+#             */
/*   Updated: 2026/06/20 19:52:58 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "game.h"


void	init_sideDist(t_ray *ray, t_player_pos *p_pos);
int		dda(t_ray *ray, char **map);
void	calc_render(t_window *win, t_ray *ray, t_render *rend);

#endif
