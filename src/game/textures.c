/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:24:31 by coressor          #+#    #+#             */
/*   Updated: 2026/07/05 18:48:40 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init_text(t_text *tex, t_ray *ray, t_render *rend, t_window *w)
{
	tex->buf = mlx_get_data_addr(ray->tex, &tex->bpp, &tex->line, &tex->endian);
	if (!tex->buf)
		return (0);
	tex->step = (double)ray->tex_h / (double)rend->lineheight;
	tex->pos = (rend->drawstart - w->sizey / 2 + rend->lineheight / 2)
		* tex->step;
	return (1);
}
static void	setText(t_ray *ray, void *tex, int tex_w, int tex_h)
{
	ray->tex = tex;
	ray->tex_w = tex_w;
	ray->tex_h = tex_h;
}

void	choose_text(t_ray *ray, t_player *player, t_window *win)
{
	if (ray->side == 0)
	{
		ray->wallx = player->p_pos->y + ray->perpwall * ray->ray[1];
		if (ray->ray[0] > 0)
			setText(ray, win->img.we, win->img.we_w, win->img.we_h);
		else
			setText(ray, win->img.ea, win->img.ea_w, win->img.ea_h);
	}
	else
	{
		ray->wallx = player->p_pos->x + ray->perpwall * ray->ray[0];
		if (ray->ray[1] > 0)
			setText(ray, win->img.so, win->img.so_w, win->img.so_h);
		else
			setText(ray, win->img.no, win->img.no_w, win->img.no_h);
	}
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)ray->tex_w);
	if (ray->side == 0 && ray->ray[0] > 0)
		ray->texx = ray->tex_w - ray->texx - 1;
	if (ray->side == 1 && ray->ray[1] < 0)
		ray->texx = ray->tex_w - ray->texx - 1;
}

void	put_wall_pixel(t_render *rend, t_window *w, t_text *tex, t_ray *ray)
{
	int	texy;

	if (rend->y == rend->drawend || rend->y == rend->drawstart)
		*(int *)rend->px = 0xFFFFFF;
	else if (rend->y < rend->drawstart)
		*(int *)rend->px = w->ceil;
	else if (rend->y > rend->drawend)
		*(int *)rend->px = w->floor;
	else
	{
		texy = (int)tex->pos;
		if (texy < 0)
			texy = 0;
		if (texy >= ray->tex_h)
			texy = ray->tex_h - 1;
		*(int *)rend->px = *(int *)(tex->buf + texy * tex->line
				+ ray->texx * (tex->bpp / 8));
		tex->pos += tex->step;
	}
}
