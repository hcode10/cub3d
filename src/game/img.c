/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:44:43 by coressor          #+#    #+#             */
/*   Updated: 2026/07/04 18:17:43 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	*free_img(t_imag *img, void *mlx)
{
	if (img)
	{
		if (img->walls)
			mlx_destroy_image(mlx, img->walls);
		if (img->no)
			mlx_destroy_image(mlx, img->no);
		if (img->so)
			mlx_destroy_image(mlx, img->so);
		if (img->we)
			mlx_destroy_image(mlx, img->we);
		if (img->ea)
			mlx_destroy_image(mlx, img->ea);
	}
	return (NULL);
}

void	*init_img(t_imag *i, t_window *w, t_map *map)
{
	i->bitspp = 32;
	i->endian = 1;
	i->walls = mlx_new_image(w->mlx, w->sizex, w->sizey);
	if (!i->walls)
		return (free_img(i, w->mlx));
	i->no = mlx_xpm_file_to_image(w->mlx, map->texture_no, &i->no_h, &i->no_w);
	if (!i->no)
		return (free_img(i, w->mlx));
	i->so = mlx_xpm_file_to_image(w->mlx, map->texture_so, &i->so_h, &i->so_w);
	if (!i->so)
		return (free_img(i, w->mlx));
	i->we = mlx_xpm_file_to_image(w->mlx, map->texture_we, &i->we_h, &i->we_w);
	if (!i->we)
		return (free_img(i, w->mlx));
	i->ea = mlx_xpm_file_to_image(w->mlx, map->texture_ea, &i->ea_h, &i->ea_w);
	if (!i->ea)
		return (free_img(i, w->mlx));
	return (i);
}
