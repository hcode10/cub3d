/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:11:43 by coressor          #+#    #+#             */
/*   Updated: 2026/07/01 09:19:10 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	init_sideDist(t_ray *ray, t_player_pos *p_pos)
{
	if (ray->ray[0] < 0)
	{
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
	int	side;

	touch = 0;
	while (!touch)
	{
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
		if (map[ray->mapy][ray->mapx] == '1')
			touch = 1;
	}
	ray->side = side;
	return (side);
}

void	calc_render(t_window *win, t_ray *ray, t_render *rend)
{
	rend->lineheight = (int)(win->sizey / ray->perpwall);
	rend->drawstart = -rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawstart < 0)
		rend->drawstart = 0;
	rend->drawend = rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawend > win->sizey)
		rend->drawend = win->sizey - 1;
}
