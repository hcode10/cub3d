/* ************************************************************************** */ /*                                                                            */ /*                                                        :::      ::::::::   */
/*   ceilnfloor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:04:19 by coressor          #+#    #+#             */
/*   Updated: 2026/06/12 11:32:24 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/window.h"
#include "../../includes/parsing.h"

static int	convert_to_rgb(int	col[3])
{
	int rgb;
	int i;

	rgb = 0;
	i = 0;
	while (i < 3)
	{
		rgb |= col[i];
		rgb <<= 2;	
		i++;
	}
	return (rgb);
}

int	draw(t_map *map, t_window *win)
{
	printf("%d", convert_to_rgb(map->sky_color));
	(void)win;	
	return (1);	
}
