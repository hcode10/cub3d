/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:59:43 by coressor          #+#    #+#             */
/*   Updated: 2026/07/01 09:17:29 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "parsing.h"
# include "window.h"
# include <math.h>

typedef struct s_player
{
	double			plane[2];
	double			dir[2];
	t_player_pos	*p_pos;
}	t_player;
typedef struct s_render
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	char	*buf;
	char	*px;
}	t_render;

typedef struct s_ray
{
	double	*plane;
	double	*dir;
	double	ray[2];
	double	cam;
	double	perpwall;
	double	sidedist[2];
	double	deltadist[2];
	int		side;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
}	t_ray;

void	init_player(t_player *game, t_player_pos *p_pos, char **map);
void	init_ray(t_player *player, t_ray *ray);
void	*render_walls(t_player *player, t_window *win, t_map *map);
void	*draw_walls(t_ray *ray, t_window *win, int x);

#endif
