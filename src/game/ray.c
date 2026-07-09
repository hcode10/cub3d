/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:23:15 by coressor          #+#    #+#             */
/*   Updated: 2026/07/08 15:16:06 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	init_ray(t_player *player, t_ray *ray)
{
	ft_bzero(ray, sizeof(t_ray));
	ray->dir = player->dir;
	ray->plane = player->plane;
}

static void	update_ray(t_ray *ray, t_window *win, t_player_pos *p_pos, int x)
{
	ray->cam = 2.0 * x / win->sizex - 1;
	ray->ray[0] = ray->dir[0] + ray->plane[0] * ray->cam;
	ray->ray[1] = ray->dir[1] + ray->plane[1] * ray->cam;
	if (ray->ray[0] == 0)
		ray->deltadist[0] = 1e30;
	else
		ray->deltadist[0] = fabs(1 / ray->ray[0]);
	if (ray->ray[1] == 0)
		ray->deltadist[1] = 1e30;
	else
		ray->deltadist[1] = fabs(1 / ray->ray[1]);
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
		init_sidedist(&ray, player->p_pos);
		if (!dda(&ray, map->map))
			ray.perpwall = ray.sidedist[0] - ray.deltadist[0];
		else
			ray.perpwall = ray.sidedist[1] - ray.deltadist[1];
		choose_text(&ray, player, win);
		if (!draw_walls(&ray, win, x))
			return (NULL);
		x++;
	}
	if (!mlx_put_image_to_window(win->mlx, win->win, win->img.walls, 0, 0))
		return (NULL);
	return (win);
}

static void	*init_rend(t_render *rend, t_ray *ray, t_window *win)
{
	t_imag	*img;

	img = &win->img;
	calc_render(win, ray, rend);
	rend->buf = mlx_get_data_addr(img->walls, &img->bitspp, &img->line_len, &img->endian);
	if (!rend->buf)
		return (NULL);
	return (rend);
}

void	*draw_walls(t_ray *ray, t_window *w, int x)
{
	t_render	rend;
	t_text		tex;

	rend.y = 0;
	if (!init_rend(&rend, ray, w))
		return (NULL);
	if (!init_text(&tex, ray, &rend, w))
		return (NULL);
	while (rend.y < w->sizey)
	{
		rend.px = rend.buf + (rend.y * w->img.line_len
				+ x * (w->img.bitspp / 8));
		put_wall_pixel(&rend, w, &tex, ray);
		rend.y++;
	}
	return (ray);
}

