/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:44:43 by coressor          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	destroy_tex(t_tex *t, void *mlx)
{
	if (t->img)
		mlx_destroy_image(mlx, t->img);
	t->img = NULL;
	t->buf = NULL;
}

void	*free_img(t_imag *img, void *mlx)
{
	if (!img || !mlx)
		return (NULL);
	if (img->walls)
		mlx_destroy_image(mlx, img->walls);
	img->walls = NULL;
	img->buf = NULL;
	destroy_tex(&img->no, mlx);
	destroy_tex(&img->so, mlx);
	destroy_tex(&img->we, mlx);
	destroy_tex(&img->ea, mlx);
	return (NULL);
}

static void	*load_tex(t_tex *t, void *mlx, char *path)
{
	t->img = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
	if (!t->img)
		return (NULL);
	t->buf = mlx_get_data_addr(t->img, &t->bpp, &t->line, &t->endian);
	if (!t->buf || t->w <= 0 || t->h <= 0)
		return (NULL);
	return (t->img);
}

void	*init_img(t_imag *i, t_window *w, t_map *map)
{
	i->walls = mlx_new_image(w->mlx, w->sizex, w->sizey);
	if (!i->walls)
		return (free_img(i, w->mlx));
	i->buf = mlx_get_data_addr(i->walls, &i->bitspp, &i->line_len, &i->endian);
	if (!i->buf)
		return (free_img(i, w->mlx));
	if (!load_tex(&i->no, w->mlx, map->texture_no)
		|| !load_tex(&i->so, w->mlx, map->texture_so)
		|| !load_tex(&i->we, w->mlx, map->texture_we)
		|| !load_tex(&i->ea, w->mlx, map->texture_ea))
		return (free_img(i, w->mlx));
	return (i);
}
