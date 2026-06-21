/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:23:15 by coressor          #+#    #+#             */
/*   Updated: 2026/06/21 14:33:13 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/utils.h"

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
	ray->deltadist[0] = sqrt(1 + pow(ray->ray[1] / ray->ray[0], 2));
	ray->deltadist[1] = sqrt(1 + pow(ray->ray[0] / ray->ray[1], 2));
	ray->stepx = 0;
	ray->stepy = 0;
	ray->mapx = (int)p_pos->x;
	ray->mapy = (int)p_pos->y;
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
		if (!dda(&ray, map->map))
			ray.perpwall = ray.sidedist[0] - ray.deltadist[0];
		else
			ray.perpwall = ray.sidedist[1] - ray.deltadist[1];
		if (!draw_walls(&ray, win, x))
			return (NULL);
		x++;
	}
	return (win);
}

static void	*init_rend(t_render *rend, t_ray *ray, t_window *win)
{
	t_imag	*img;

	img = &win->img;
	calc_render(win, ray, rend);
	rend->buf = mlx_get_data_addr(img->walls, &img->bitspp, &win->sizex,
			&img->endian);
	if (!rend->buf)
		return (NULL);
	return (rend);
}

void	*draw_walls(t_ray *ray, t_window *w, int x)
{
	t_render	rend;
	int			y;

	if (!init_rend(&rend, ray, w))
		return (NULL);
	y = rend.drawstart;
	while (y < rend.drawend)
	{
		rend.px = rend.buf + (y * w->sizex + x * (w->img.bitspp / 8));
		*(int *)rend.px = 0;
		y++;
	}
	return (ray);
}

