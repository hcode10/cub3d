/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:44:43 by coressor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/21 13:50:56 by coressor         ###   ########.fr       */
=======
/*   Updated: 2026/06/20 19:33:16 by coressor         ###   ########.fr       */
>>>>>>> b336579 (merging dev)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

void	*free_img(t_imag *img, void *mlx)
{
	if (img)
<<<<<<< HEAD
	{
		if (img->back)
			mlx_destroy_image(mlx, img->back);
		if (img->no)
			mlx_destroy_image(mlx, img->no);
		if (img->so)
			mlx_destroy_image(mlx, img->so);
		if (img->we)
			mlx_destroy_image(mlx, img->we);
		if (img->ea)
			mlx_destroy_image(mlx, img->ea);
=======
	{		
		if (img->back)
			mlx_destroy_image(mlx,img->back);
		if (img->no)
			mlx_destroy_image(mlx,img->no);
		if (img->so)
			mlx_destroy_image(mlx,img->so);
		if (img->we)
			mlx_destroy_image(mlx,img->we);	
		if (img->ea)
			mlx_destroy_image(mlx,img->ea);
>>>>>>> b336579 (merging dev)
	}
	return (NULL);
}

void	*init_img(t_imag *i, t_window *w, t_map *map)
{
<<<<<<< HEAD
	i->h = 480;
	i->w = 480;
	i->bitspp = 32;
	i->endian = 1;
	i->back = mlx_new_image(w->mlx, w->sizex, w->sizey);
	if (!i->back)
		return (free_img(i, w->mlx));
	i->walls = mlx_new_image(w->mlx, w->sizex, w->sizey);
	if (!i->walls)
		return (free_img(i, w->mlx));
	i->no = mlx_xpm_file_to_image(w->mlx, map->texture_no, &i->h, &i->w);
	if (!i->no)
		return (free_img(i, w->mlx));
	i->so = mlx_xpm_file_to_image(w->mlx, map->texture_so, &i->h, &i->w);
	if (!i->so)
		return (free_img(i, w->mlx));
	i->we = mlx_xpm_file_to_image(w->mlx, map->texture_we, &i->h, &i->w);
	if (!i->we)
		return (free_img(i, w->mlx));
	i->ea = mlx_xpm_file_to_image(w->mlx, map->texture_ea, &i->h, &i->w);
	if (!i->ea)
		return (free_img(i, w->mlx));
=======
		i->h = 480;
		i->w = 480;
		i->bitspp = 32;
		i->endian = 1;
		i->back = mlx_new_image(w->mlx, w->sizex, w->sizey);
		if (!i->back)
			return (free_img(i, w->mlx));
		i->walls = mlx_new_image(w->mlx, w->sizex, w->sizey);
		if (!i->walls)
			return (free_img(i, w->mlx));
		i->no = mlx_xpm_file_to_image(w->mlx, map->texture_no, &i->h, &i->w);
		if (!i->no)
			return (free_img(i, w->mlx));
		i->so = mlx_xpm_file_to_image(w->mlx, map->texture_so, &i->h, &i->w);
		if (!i->so)
			return (free_img(i, w->mlx));
		i->we = mlx_xpm_file_to_image(w->mlx, map->texture_we, &i->h, &i->w);
		if (!i->we)
			return (free_img(i, w->mlx));
		i->ea = mlx_xpm_file_to_image(w->mlx, map->texture_ea, &i->h, &i->w);
		if (!i->ea)
			return (free_img(i, w->mlx));
>>>>>>> b336579 (merging dev)
	return (i);
}
