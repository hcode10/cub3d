/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:30:00 by coressor          #+#    #+#             */
/*   Updated: 2026/06/20 18:18:52 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

static int	convert_to_rgb(int	col[3])
{
	int rgb;
	int i;

	rgb = 0;
	i = 0;
	while (i < 2) {
		rgb |= col[i];
		rgb = rgb << 8;	
		i++;
	}	
	rgb |= col[i];
	return (rgb);
}
/**
 * @brief Initialisation for window struct
 * @return void* - the pointer of the window or NULL
 */
void	*init_window(t_map *map)
{
	t_window	*swn;

	swn = ft_calloc(1, sizeof(t_window));
	if (!swn)
		return (NULL);
	swn->title = "CUB3D";
	swn->mlx = mlx_init();
	if (!swn->mlx)
		return (NULL);
	if (!mlx_get_screen_size(swn->mlx, &swn->sizex, &swn->sizey))
			return (NULL);
	swn->win = mlx_new_window(swn->mlx, swn->sizex, swn->sizey, swn->title); 
	if (!swn->win)
		return (NULL);	
	swn->ceil = convert_to_rgb(map->sky_color);
	swn->floor = convert_to_rgb(map->floor_color);
	if (!init_img(&swn->img, swn, map))
		return (NULL);
	return (swn);
}

void	free_window(t_window *s_win)
{
	if (s_win)
	{
		if (s_win->mlx)
			free_img(&s_win->img, s_win->mlx);
		if (s_win->win)	
			mlx_destroy_window(s_win->mlx, s_win->win);
		if (s_win->mlx)
		{
			mlx_destroy_display(s_win->mlx);
			free(s_win->mlx);
		}
		free(s_win);
	}
}
