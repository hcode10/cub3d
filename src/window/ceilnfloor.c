/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilnfloor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:02:29 by coressor          #+#    #+#             */
/*   Updated: 2026/06/14 16:07:20 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

int	create_back(t_window *win)
{
	int		i;
	int		y;
	void	*px;
	char	*buf;

	i = 0;
	buf = mlx_get_data_addr(win->back, &win->bitspp, &win->sizex, &win->endian);
	if (!buf)
		return (0);
	while (i < win->sizex)
	{
		y = 0;
		while (y < win->sizey)
		{
			px =  buf + (y * win->sizex + i * (win->bitspp / 8));
			if (y < win->sizey / 2)
				*(int *)px = win->floor;
			else
				*(int *)px = win->ceil;
			y++;
		}
		i++;
	}
	return (1);	
}

int	draw_back(t_window *win)
{
	if (mlx_put_image_to_window(win->mlx, win->win, win->back, 0, 0))
		return (1);
	return (0); 
}
