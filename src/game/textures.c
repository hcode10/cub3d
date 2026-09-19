/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:24:31 by coressor          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_text(t_text *tex, t_ray *ray, t_render *rend, t_window *w)
{
	tex->step = (double)ray->tex->h / (double)rend->lineheight;
	tex->pos = (rend->drawstart - w->sizey / 2 + rend->lineheight / 2)
		* tex->step;
}

static void	clamp_texx(t_ray *ray)
{
	if ((ray->side == 0 && ray->ray[0] < 0)
		|| (ray->side == 1 && ray->ray[1] > 0))
		ray->texx = ray->tex->w - ray->texx - 1;
	if (ray->texx < 0)
		ray->texx = 0;
	if (ray->texx >= ray->tex->w)
		ray->texx = ray->tex->w - 1;
}

void	choose_text(t_ray *ray, t_player *player, t_window *win)
{
	if (ray->side == 0)
	{
		ray->wallx = player->p_pos->y + ray->perpwall * ray->ray[1];
		if (ray->ray[0] > 0)
			ray->tex = &win->img.ea;
		else
			ray->tex = &win->img.we;
	}
	else
	{
		ray->wallx = player->p_pos->x + ray->perpwall * ray->ray[0];
		if (ray->ray[1] > 0)
			ray->tex = &win->img.so;
		else
			ray->tex = &win->img.no;
	}
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)ray->tex->w);
	clamp_texx(ray);
}

void	put_wall_pixel(t_render *rend, t_window *w, t_text *tex, t_ray *ray)
{
	int	texy;

	if (rend->y < rend->drawstart)
		*(int *)rend->px = w->ceil;
	else if (rend->y > rend->drawend)
		*(int *)rend->px = w->floor;
	else
	{
		texy = (int)tex->pos;
		if (texy < 0)
			texy = 0;
		if (texy >= ray->tex->h)
			texy = ray->tex->h - 1;
		*(int *)rend->px = *(int *)(ray->tex->buf + texy * ray->tex->line
				+ ray->texx * (ray->tex->bpp / 8));
		tex->pos += tex->step;
	}
}
