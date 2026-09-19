/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:30:00 by coressor          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	convert_to_rgb(int col[3])
{
	return ((col[0] << 16) | (col[1] << 8) | col[2]);
}

/**
 * @brief mlx_get_screen_size() ne renvoie rien d'exploitable : on lit
 * seulement les valeurs qu'il ecrit, puis on borne la fenetre.
 */
static void	set_size(t_window *w)
{
	w->sizex = 0;
	w->sizey = 0;
	mlx_get_screen_size(w->mlx, &w->sizex, &w->sizey);
	if (w->sizex <= 0 || w->sizex > WIN_MAX_W)
		w->sizex = WIN_MAX_W;
	if (w->sizey <= 0 || w->sizey > WIN_MAX_H)
		w->sizey = WIN_MAX_H;
}

void	*init_window(t_map *map)
{
	t_window	*w;

	w = ft_calloc(1, sizeof(t_window));
	if (!w)
		return (NULL);
	w->title = "cub3D";
	w->mlx = mlx_init();
	if (!w->mlx)
		return (free(w), NULL);
	set_size(w);
	w->ceil = convert_to_rgb(map->sky_color);
	w->floor = convert_to_rgb(map->floor_color);
	w->win = mlx_new_window(w->mlx, w->sizex, w->sizey, w->title);
	if (!w->win)
		return (free_window(w), NULL);
	if (!init_img(&w->img, w, map))
		return (free_window(w), NULL);
	return (w);
}

void	free_window(t_window *s_win)
{
	if (!s_win)
		return ;
	if (s_win->mlx)
		free_img(&s_win->img, s_win->mlx);
	if (s_win->mlx && s_win->win)
		mlx_destroy_window(s_win->mlx, s_win->win);
	if (s_win->mlx)
	{
		mlx_destroy_display(s_win->mlx);
		free(s_win->mlx);
	}
	free(s_win);
}
