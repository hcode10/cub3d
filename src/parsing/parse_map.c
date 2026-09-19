/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	check_element_line(char *line)
{
	char	*clean;
	bool	ok;

	clean = clean_line(line);
	if (!clean)
		return (false);
	ok = (match_element(clean) == 1);
	free(clean);
	return (ok);
}

static bool	read_elements(int fd, char **line_after)
{
	char	*line;
	int		line_ok;

	line_ok = 0;
	line = get_next_line(fd);
	while (line && line_ok < 6)
	{
		if (!space_only(line))
		{
			if (!check_element_line(line))
				return (free(line), *line_after = NULL, false);
			line_ok++;
		}
		free(line);
		line = get_next_line(fd);
	}
	*line_after = line;
	return (line_ok == 6);
}

static bool	rest_is_blank(int fd, char *line)
{
	while (line != NULL)
	{
		if (!space_only(line))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

static bool	read_grid(int fd, t_map *map, char *line)
{
	while (line && space_only(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (false);
	while (line != NULL)
	{
		if (space_only(line))
			return (rest_is_blank(fd, line));
		if (!add_map_line(map, line))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

bool	get_map(char *map_path, t_map *map)
{
	int		fd;
	char	*line;
	bool	ok;

	line = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	ok = read_elements(fd, &line);
	if (ok)
		ok = read_grid(fd, map, line);
	drain_gnl(fd);
	close(fd);
	if (!ok || !map->map || !map->map[0])
		return (false);
	map->map_dup = copy_map(map->map);
	if (!map->map_dup)
		return (false);
	return (normalize_map(map));
}
