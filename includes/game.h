/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:59:43 by coressor          #+#    #+#             */
/*   Updated: 2026/06/20 20:12:25 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "parsing.h"
# include "window.h"
# include <math.h>
# include "utils.h"

typedef struct s_player
{
	double	plane[2];
	double	dir[2];
	t_player_pos *p_pos;
} t_player;

typedef struct s_render
{
	int		lineheight;
	int		drawStart;
	int 	drawEnd;
	char	*buf;
	char	*px;
}	t_render;

typedef struct s_ray
{
	double *plane;
	double *dir;
	double ray[2];
	double cam;
	double perpWall;
	double sideDist[2];
	double deltaDist[2];
	int		side;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
} t_ray;

// Init la map en faisant l'operation sur le player en fonction de la ou il regarde
void	init_player(t_player *game, t_player_pos *p_pos, int dirX, int dirY);
void	init_ray(t_player *player, t_ray *ray);
void	*render_walls(t_player *player, t_window *win, t_map *map);
void	*draw_walls(t_ray *ray,  t_window *win, int x);

#endif
