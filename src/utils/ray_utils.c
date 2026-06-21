/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:11:43 by coressor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/21 14:34:10 by coressor         ###   ########.fr       */
=======
/*   Updated: 2026/06/20 19:52:39 by coressor         ###   ########.fr       */
>>>>>>> b336579 (merging dev)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	init_sideDist(t_ray *ray, t_player_pos *p_pos)
{
	if (ray->ray[0] < 0)
	{
<<<<<<< HEAD
		ray->sidedist[0] = (p_pos->x - ray->mapx) * ray->deltadist[0];
		ray->stepx = -1;
	}
	else
	{
		ray->sidedist[0] = (ray->mapx + 1 - p_pos->x) * ray->deltadist[0];
		ray->stepx = 1;
	}
	if (ray->ray[1] < 0)
	{
		ray->sidedist[1] = (p_pos->y - ray->mapy) * ray->deltadist[1];
		ray->stepy = -1;
	}
	else
	{
		ray->sidedist[1] = (ray->mapy + 1 - p_pos->x) * ray->deltadist[1];
		ray->stepy = 1;
	}
}

int	dda(t_ray *ray, char **map)
{
	int	touch;
=======
		ray->sideDist[0] = (p_pos->x - ray->mapX) * ray->deltaDist[0];
		ray->stepX = -1;
	}
	else
	{
		ray->sideDist[0] = (ray->mapX + 1 - p_pos->x) * ray->deltaDist[0];
		ray->stepX = 1;
	}
	if (ray->ray[1] < 0)
	{
		ray->sideDist[1] = (p_pos->y - ray->mapY) * ray->deltaDist[1];
		ray->stepY = -1;
	}
	else
	{
		ray->sideDist[1] = (ray->mapY + 1 - p_pos->x) * ray->deltaDist[1];
		ray->stepY = 1;
	}
}

int		dda(t_ray *ray, char **map)
{
	int touch;
>>>>>>> b336579 (merging dev)
	int	side;

	touch = 0;
	while (!touch)
	{
<<<<<<< HEAD
		if (ray->sidedist[0] < ray->sidedist[1])
		{
			ray->sidedist[0] += ray->deltadist[0];
			ray->mapx += ray->stepx;
			side = 0;
		}
		else
		{
			ray->sidedist[1] += ray->deltadist[1];
			ray->mapy += ray->stepy;
			side = 1;
		}
		if (map[ray->mapx][ray->mapy] == '1')
			touch = 1;
=======
		if (ray->sideDist[0] < ray->sideDist[1])
		{
			ray->sideDist[0] += ray->deltaDist[0];
			ray->mapX += ray->stepX;
			side = 0;
		}
		else 
		{	
			ray->sideDist[1] += ray->deltaDist[1];
			ray->mapY += ray->stepY;
			side = 1;
		}
		if (map[ray->mapX][ray->mapY] == '1')
			touch = 1;	
>>>>>>> b336579 (merging dev)
	}
	ray->side = side;
	return (side);
}

void	calc_render(t_window *win, t_ray *ray, t_render *rend)
{
<<<<<<< HEAD
	rend->lineheight = (int)(win->sizey / ray->perpwall);
	rend->drawstart = -rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawstart < 0)
		rend->drawstart = 0;
	rend->drawend = rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawend > win->sizey)
		rend->drawend = win->sizey - 1;
=======
	rend->lineheight = (int)(win->sizey / ray->perpWall); 
	rend->drawStart = -rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawStart < 0)
		rend->drawStart = 0;
	rend->drawEnd = rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawEnd > win->sizey)
		rend->drawEnd = win->sizey - 1;
>>>>>>> b336579 (merging dev)
}
