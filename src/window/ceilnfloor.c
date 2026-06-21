/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilnfloor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:02:29 by coressor          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/06/21 14:00:56 by coressor         ###   ########.fr       */
=======
/*   Updated: 2026/06/20 17:36:26 by coressor         ###   ########.fr       */
>>>>>>> b336579 (merging dev)
=======
/*   Updated: 2026/06/21 14:00:56 by coressor         ###   ########.fr       */
>>>>>>> 91440b8 (raycast)
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
<<<<<<< HEAD
<<<<<<< HEAD
			px = buf + (y * w->sizex + i * (img->bitspp / 8));
=======
			px =  buf + (y * w->sizex + i * (img->bitspp / 8));
>>>>>>> b336579 (merging dev)
=======
			px = buf + (y * w->sizex + i * (img->bitspp / 8));
>>>>>>> 91440b8 (raycast)
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
