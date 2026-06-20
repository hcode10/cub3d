/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilnfloor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:02:29 by coressor          #+#    #+#             */
/*   Updated: 2026/06/20 17:36:26 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"

int	create_back(t_window *w, t_imag *img)
{
	int		i;
	int		y;
	void	*px;
	char	*buf;

	i = 0;
	buf = mlx_get_data_addr(img->back, &img->bitspp, &w->sizex, &img->endian);
	if (!buf)
		return (0);
	while (i < w->sizex)
	{
		y = 0;
		while (y < w->sizey)
		{
			px =  buf + (y * w->sizex + i * (img->bitspp / 8));
			if (y < w->sizey / 2)
				*(int *)px = w->floor;
			else
				*(int *)px = w->ceil;
			y++;
		}
		i++;
	}
	return (1);	
}

int	draw_back(t_window *win)
{
	if (mlx_put_image_to_window(win->mlx, win->win, win->img.back, 0, 0))
		return (1);
	return (0); 
}
