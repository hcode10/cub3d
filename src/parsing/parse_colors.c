/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/07 19:35:11 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	check_numeric_color(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_strchr(" \n,", rgb[i][j]) && !ft_isdigit(rgb[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
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

static bool	parse_rgb(int *dst, char **rgb)
{
	if (!rgb || count_tabs(rgb) != 3 || !check_numeric_color(rgb))
		return (false);
	dst[0] = ft_atoi(rgb[0]);
	dst[1] = ft_atoi(rgb[1]);
	dst[2] = ft_atoi(rgb[2]);
	return (true);
}

static bool	handle_color_line(t_map *map, char *line, char **splited)
{
	char	*clean;
	char	**rgb;
	bool	ok;

	if (!splited[0] || splited[0][1] != '\0')
		return (true);
	if (splited[0][0] != 'F' && splited[0][0] != 'C')
		return (true);
	clean = no_spaces(line);
	if (!clean)
		return (false);
	rgb = ft_split(&clean[1], ',');
	free(clean);
	if (!rgb)
		return (false);
	if (splited[0][0] == 'F')
		ok = parse_rgb(map->floor_color, rgb);
	else
		ok = parse_rgb(map->sky_color, rgb);
	return (free_tabs(rgb), ok);
}

bool	set_color(t_map *map, char *map_path)
{
	char	*line;
	char	**splited;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line != NULL)
	{
		splited = ft_split(line, ' ');
		if (!splited)
			return (close(fd), free(line), false);
		if (!handle_color_line(map, line, splited))
			return (close(fd), free_tabs(splited), free(line), false);
		free_tabs(splited);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}
