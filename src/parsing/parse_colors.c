/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	parse_rgb(int *dst, char *value)
{
	char	**rgb;
	char	*clean;
	bool	ok;

	clean = no_spaces(value);
	if (!clean)
		return (false);
	if (count_commas(clean) != 2)
		return (free(clean), false);
	rgb = ft_split(clean, ',');
	free(clean);
	if (!rgb)
		return (false);
	ok = (count_tabs(rgb) == 3 && fill_rgb(dst, rgb));
	return (free_tabs(rgb), ok);
}

bool	handle_color_line(t_map *map, char *clean)
{
	if ((clean[0] != 'F' && clean[0] != 'C') || clean[1] != ' ')
		return (true);
	if (clean[0] == 'F')
	{
		if (map->f_set)
			return (false);
		map->f_set = 1;
		return (parse_rgb(map->floor_color, clean + 1));
	}
	if (map->c_set)
		return (false);
	map->c_set = 1;
	return (parse_rgb(map->sky_color, clean + 1));
}

bool	check_color(int *sky_color, int *floor_color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (sky_color[i] < 0 || sky_color[i] > 255)
			return (false);
		if (floor_color[i] < 0 || floor_color[i] > 255)
			return (false);
		i++;
	}
	return (true);
}
