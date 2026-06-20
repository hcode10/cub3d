/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:11:43 by coressor          #+#    #+#             */
/*   Updated: 2026/06/20 19:52:39 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	init_sideDist(t_ray *ray, t_player_pos *p_pos)
{
	if (ray->ray[0] < 0)
	{
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
	int	side;

	touch = 0;
	while (!touch)
	{
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
	}
	ray->side = side;
	return (side);
}

void	calc_render(t_window *win, t_ray *ray, t_render *rend)
{
	rend->lineheight = (int)(win->sizey / ray->perpWall); 
	rend->drawStart = -rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawStart < 0)
		rend->drawStart = 0;
	rend->drawEnd = rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawEnd > win->sizey)
		rend->drawEnd = win->sizey - 1;
}
