/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:51:47 by coressor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/01 09:02:38 by coressor         ###   ########.fr       */
=======
/*   Updated: 2026/06/21 14:06:46 by coressor         ###   ########.fr       */
>>>>>>> 91440b8 (raycast)
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "game.h"

void	init_sideDist(t_ray *ray, t_player_pos *p_pos);
int		dda(t_ray *ray, char **map);
void	calc_render(t_window *win, t_ray *ray, t_render *rend);

#endif
