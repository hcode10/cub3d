/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/14 20:46:28 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>

static int	match_element(char **splited)
{
	if (ft_strncmp("NO", splited[0], 2) == 0
		|| ft_strncmp("SO", splited[0], 2) == 0
		|| ft_strncmp("WE", splited[0], 2) == 0
		|| ft_strncmp("EA", splited[0], 2) == 0
		|| ft_strncmp("F", splited[0], 1) == 0
		|| ft_strncmp("C", splited[0], 1) == 0)
		return (1);
	return (0);
}

static bool	read_elements(int fd, char **line_after)
{
	char	*line;
	char	**splited;
	int		line_ok;

	line_ok = 0;
	line = get_next_line(fd);
	while (line && line_ok != 6)
	{
		if (space_only(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		splited = ft_split(line, ' ');
		if (!splited || !match_element(splited))
			return (free_tabs(splited), free(line), *line_after = NULL, false);
		line_ok++;
		free_tabs(splited);
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
			return (dbg_fail("read_grid", "contenu apres la map"),
				free(line), false);
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
	map->map = NULL;
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

	line = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (dbg_step("get_map: open() echoue"), false);
	if (!read_elements(fd, &line))
		return (dbg_fail("get_map", "read_elements KO (<6 elts/ligne KO)"),
			free(line), close(fd), false);
	dbg_step("get_map: 6 elements OK, lecture grille");
	if (!read_grid(fd, map, line))
		return (dbg_fail("get_map", "read_grid KO"), close(fd), false);
	close(fd);
	map->map_dup = copy_map(map->map);
	if (!map->map_dup)
		return (false);
	normalize_map(map);
	dbg_map(map);
	return (true);
}
