/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:11:43 by coressor          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_sidedist(t_ray *ray, t_player_pos *p_pos)
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
		ray->sidedist[1] = (ray->mapy + 1 - p_pos->y) * ray->deltadist[1];
		ray->stepy = 1;
	}
}

int	is_wall(char **map, double x, double y)
{
	int	mx;
	int	my;

	if (x < 0 || y < 0)
		return (1);
	mx = (int)x;
	my = (int)y;
	if (my < 0 || mx < 0)
		return (1);
	if (!map[my])
		return (1);
	if (mx >= (int)ft_strlen(map[my]))
		return (1);
	return (map[my][mx] == '1' || map[my][mx] == ' ');
}

int	dda(t_ray *ray, char **map)
{
	int	side;

	side = 0;
	while (1)
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
		if (is_wall(map, (double)ray->mapx, (double)ray->mapy))
			break ;
	}
	ray->side = side;
	return (side);
}

void	calc_render(t_window *win, t_ray *ray, t_render *rend)
{
	double	h;

	if (!(ray->perpwall > 0.0001))
		ray->perpwall = 0.0001;
	h = win->sizey / ray->perpwall;
	if (h > win->sizey * 1000.0)
		h = win->sizey * 1000.0;
	rend->lineheight = (int)h;
	if (rend->lineheight < 1)
		rend->lineheight = 1;
	rend->drawstart = -rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawstart < 0)
		rend->drawstart = 0;
	rend->drawend = rend->lineheight / 2 + win->sizey / 2;
	if (rend->drawend >= win->sizey)
		rend->drawend = win->sizey - 1;
}

void	exit_win(t_game *win, int code)
{
	free_struct(&win->maps);
	free_window(win->win);
	exit(code);
}
