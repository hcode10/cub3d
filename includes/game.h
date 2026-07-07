/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:59:43 by coressor          #+#    #+#             */
/*   Updated: 2026/07/05 18:50:52 by coressor         ###   ########.fr       */
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

typedef struct s_text
{
	char	*buf;
	int		bpp;
	int		line;
	int		endian;
	double	step;
	double	pos;
}	t_text;

typedef struct s_render
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		y;
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
	double	wallx;   
	void	*tex;    
	int		tex_w;   
	int		tex_h;   
	int		texx; 
}	t_ray;

void	init_player(t_player *game, t_player_pos *p_pos, char **map);
void	init_ray(t_player *player, t_ray *ray);
void	*render_walls(t_player *player, t_window *win, t_map *map);
void	*draw_walls(t_ray *ray, t_window *win, int x);
void	put_wall_pixel(t_render *rend, t_window *w, t_text *tex, t_ray *ray);
void	choose_text(t_ray *ray, t_player *player, t_window *win);
int		init_text(t_text *tex, t_ray *ray, t_render *rend, t_window *w);

#endif
