/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:23:15 by coressor          #+#    #+#             */
/*   Updated: 2026/06/20 20:11:44 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	init_ray(t_player *player, t_ray *ray)
{
	ray->dir = player->dir;
	ray->plane = player->plane;
}

static void	update_ray(t_ray *ray, t_window *win, t_player_pos *p_pos, int x)
{
	ray->cam = 2 * x / win->sizex - 1;
	ray->ray[0] = ray->dir[0] + ray->plane[0] * ray->cam;
	ray->ray[1] = ray->dir[1] + ray->plane[1] * ray->cam;
	ray->deltaDist[0] = sqrt(1 + pow(ray->ray[1] / ray->ray[0], 2));
	ray->deltaDist[1] = sqrt(1 + pow(ray->ray[0] / ray->ray[1], 2));
	ray->stepX = 0;
	ray->stepY = 0;
	ray->mapX = (int)p_pos->x;
	ray->mapY = (int)p_pos->y;
	(void) win;
	(void) p_pos;
}

void	*render_walls(t_player *player, t_window *win, t_map *map)
{
	int		x;
	t_ray	ray;

	x = 0;
	init_ray(player, &ray);
	while (x < win->sizex)
	{
		update_ray(&ray, win, player->p_pos, x);
		init_sideDist(&ray, player->p_pos);
		if (!dda(ray, map->map))
			ray.perpWall = ray.sideDist[0] - ray.deltaDist[0];
		else
			ray.perpWall = ray.sideDist[1] - ray.deltaDist[1];
		if (!draw_walls(&ray,  win, x))
			return (NULL);
		x++;
	}
	return (win);
}

static void	*init_rend(t_render *rend, t_window *win)
{
	t_imag	*img;

	img = &win->img;
	calc_render(win, &rend);
	rend->buf = mlx_get_data_addr(img->walls, &img->bitspp , &win->sizex
			, &img->endian);
	if (!rend->buf)
		return (NULL);
	return (rend);
}

void	*draw_walls(t_ray *ray,  t_window *w, int x)
{
	t_render rend;
	int	y;

	if (!init_rend(&rend, w))
		return (NULL);
	y = rend.drawStart;
	while (y < rend.drawEnd)
	{
		rend.px =  rend.buf + (y * w->sizex + x * (w->img.bitspp / 8));
		*(int *)rend.px = 0;
		y++;
	}
}
