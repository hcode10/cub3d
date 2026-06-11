/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:30:00 by coressor          #+#    #+#             */
/*   Updated: 2026/06/10 18:02:00 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

/**
 * @brief Initialisation for window struct
 * @return void* - the pointer of the window or NULL
 */
void	*init_window()
{
	t_window	*swn;

	// ft_calloc(1, t_window);
	if (!swn)
		return (NULL);
	swn->mlx = mlx_init();
	if (!swn->mlx)
		return (NULL);
	if (mlx_get_screen_size(swn->mlx, &swn->sizex, &swn->sizey))
			return (NULL);
	// TODO cree un char* pour le titre
	swn->win = mlx_new_window(swn->mlx, swn->sizey, swn->sizex, "CUB3D");
	if (!swn->win)
		return (NULL);
	return (swn);
}

void	free_window(t_window *s_win)
{
	if (s_win)
	{
		if (s_win->win)	
			mlx_destroy_window(s_win->mlx, s_win->win);
		if (s_win->mlx)
			mlx_destroy_display(s_win->mlx);
		free(s_win);
	}
}
