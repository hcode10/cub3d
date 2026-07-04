/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/14 20:46:28 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>

bool	valid_path(char *map_path)
{
	char	*ext;

	if (!map_path || ft_strlen(map_path) < 4)
		return (dbg_fail("valid_path", "chemin trop court/NULL"), false);
	ext = map_path + (ft_strlen(map_path) - 4);
	if (ft_strncmp(ext, ".cub", 4) != 0)
		return (dbg_fail("valid_path", "extension != .cub"), false);
	return (true);
}

static bool	check_files(char *path)
{
	int	fd;

	if (!path)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	check_textures(t_map *map)
{
	if (!check_files(map->texture_ea))
		return (dbg_fail("check_textures", "EA absente/illisible"), false);
	if (!check_files(map->texture_no))
		return (dbg_fail("check_textures", "NO absente/illisible"), false);
	if (!check_files(map->texture_so))
		return (dbg_fail("check_textures", "SO absente/illisible"), false);
	if (!check_files(map->texture_we))
		return (dbg_fail("check_textures", "WE absente/illisible"), false);
	return (true);
}

static void	set_one_texture(t_map *map, char **splited)
{
	if (ft_strncmp("NO", splited[0], 2) == 0 && !map->texture_no)
		map->texture_no = ft_strtrim(splited[1], "\n");
	else if (ft_strncmp("SO", splited[0], 2) == 0 && !map->texture_so)
		map->texture_so = ft_strtrim(splited[1], "\n");
	else if (ft_strncmp("WE", splited[0], 2) == 0 && !map->texture_we)
		map->texture_we = ft_strtrim(splited[1], "\n");
	else if (ft_strncmp("EA", splited[0], 2) == 0 && !map->texture_ea)
		map->texture_ea = ft_strtrim(splited[1], "\n");
}

bool	set_textures(t_map *map, char *map_path)
{
	char	*line;
	char	*line_trim;
	char	**splited;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (dbg_fail("set_textures", "open() echoue"), false);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_trim = ft_strtrim(line, "\n");
		free(line);
		splited = ft_split(line_trim, ' ');
		free(line_trim);
		if (splited && count_tabs(splited) == 2)
			set_one_texture(map, splited);
		free_tabs(splited);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}
