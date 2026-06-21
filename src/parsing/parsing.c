/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:55 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/14 20:32:04 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>

size_t count_tabs(char **tab)
{
	size_t count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

void free_tabs(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void free_struct(t_map *map)
{
	if (map->map)
		free_split(map->map);
	if (map->map_dup)
		free(map->map_dup);
	if (map->texture_ea)
		free(map->texture_ea);
	if (map->texture_no)
		free(map->texture_no);
	if (map->texture_so)
		free(map->texture_so);
	if (map->texture_we)
		free(map->texture_we);
}

static bool	valid_path(char *map_path)
{
	char	*ext;

	if (!map_path)
		return (false);
	ext = map_path + (ft_strlen(map_path) - 4);
	if (ft_strncmp(ext, ".cub", 4) != 0)
	{
		return (false);
	}
	return (true);
}

static bool check_files(char *path)
{
	int fd;

	if (!path)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (false);
	else
	{
		close(fd);
		return (true);
	}
}

static bool	check_textures(t_map *map)
{
	if (!check_files(map->texture_ea))
		return (false);
	if (!check_files(map->texture_no))
		return (false);
	if (!check_files(map->texture_so))
		return (false);
	if (!check_files(map->texture_we))
		return (false);
	return (true);
}

static bool	check_color(int *sky_color, int *floor_color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (sky_color[i] >= 0 && sky_color[i] <= 255)
			i++;
		else
			return (false);
	}
	i = 0;
	while (i < 3)
	{
		if (floor_color[i] >= 0 && floor_color[i] <= 255)
			i++;
		else
			return (false);
	}
	return (true);
}

bool	set_textures(t_map *map, char *map_path)
{
	char	*line;
	char	**splited;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	while ((line = get_next_line(fd)) != NULL)
	{
		splited = ft_split(line, ' ');
		free(line);
		if (count_tabs(splited) != 2)
		{
			free_tabs(splited);
			continue ;
		}
		if (ft_strncmp("NO", splited[0], 2) == 0 && !map->texture_no)
			map->texture_no = ft_strtrim(splited[1], "\n");
		else if (ft_strncmp("SO", splited[0], 2) == 0 && !map->texture_so)
			map->texture_so = ft_strtrim(splited[1], "\n");
		else if (ft_strncmp("WE", splited[0], 2) == 0 && !map->texture_we)
			map->texture_we = ft_strtrim(splited[1], "\n");
		else if (ft_strncmp("EA", splited[0], 2) == 0 && !map->texture_ea)
			map->texture_ea = ft_strtrim(splited[1], "\n");
		free_tabs(splited);
	}
	close(fd);
	return (true);
}

bool	check_numeric_color(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strchr(" \n,", str[i][j]))
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(str[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	set_color(t_map *map, char *map_path)
{
	char	*line;
	char	**splited;
	char	**color_split;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd <= 0)
		return (false);
	while ((line = get_next_line(fd)) != NULL)
	{
		splited = ft_split(line, ' ');
		if (!splited)
			return (false);
		if (ft_strncmp("F", splited[0], 1) == 0)
		{
			color_split = ft_split(splited[1], ',');
			if (!color_split)
				return (free(splited), false);
			if (count_tabs(color_split) != 3 || !check_numeric_color(color_split))
				return (free_tabs(color_split), free_tabs(splited), free(line), false);
			map->floor_color[0] = ft_atoi(color_split[0]);
			map->floor_color[1] = ft_atoi(color_split[1]);
			map->floor_color[2] = ft_atoi(color_split[2]);
			free_tabs(color_split);
		}
		else if (ft_strncmp("C", splited[0], 1) == 0)
		{
			color_split = ft_split(splited[1], ',');
			if (!color_split)
				return (free_tabs(splited), false);
			if (count_tabs(color_split) != 3  || !check_numeric_color(color_split))
				return (free_tabs(color_split), free_tabs(splited), free(line), false);
			map->sky_color[0] = ft_atoi(color_split[0]);
			map->sky_color[1] = ft_atoi(color_split[1]);
			map->sky_color[2] = ft_atoi(color_split[2]);
			free_tabs(color_split);
		}
		free_tabs(splited);
		free(line);
	}
	close(fd);
	return (true);
}

bool	space_only(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
		{
			index++;
			continue ;
		}
		if (str[index] != ' ')
			return (false);
		index++;
	}
	return (true);
}

bool space_is_ugly(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '1';
			j++;
		}
		i++;
	}
	return (true);
}

static bool	add_map_line(t_map *map, char *line)
{
	size_t	n;
	size_t	i;
	char	**new;

	n = 0;
	while (map->map && map->map[n])
		n++;
	new = ft_calloc(n + 2, sizeof(char *));
	if (!new)
		return (false);
	i = 0;
	while (i < n)
	{
		new[i] = map->map[i];
		i++;
	}
	new[n] = ft_strtrim(line, "\n");
	if (!new[n])
		return (free(new), false);
	free(map->map);
	map->map = new;
	return (true);
}

bool	get_map(char *map_path, t_map *map)
{
	int		fd;
	char	*line;
	int		line_ok;
	char	**splited;

	fd = open(map_path, O_RDONLY);
	if (fd <= 0)
		return (false);
	line_ok = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line_ok == 6)
			break ;

		if (space_only(line))
		{
			free(line);
			continue ;
		}
		splited = ft_split(line, ' ');
		if (ft_strncmp("NO", splited[0], 2) == 0)
			line_ok++;
		else if (ft_strncmp("SO", splited[0], 2) == 0)
			line_ok++;
		else if (ft_strncmp("WE", splited[0], 2) == 0)
			line_ok++;
		else if (ft_strncmp("EA", splited[0], 2) == 0)
			line_ok++;
		else if (ft_strncmp("F", splited[0], 1) == 0)
			line_ok++;
		else if (ft_strncmp("C", splited[0], 1) == 0)
			line_ok++;
		else
		{
			free_tabs(splited);
			free(line);
			return (false);
		}
			
		free_tabs(splited);
		free(line);
	}
	if (line_ok != 6)
		return (false);
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
		if (!add_map_line(map, line) || space_only(line))
		{
			free(line);
			close(fd);
			return (false);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	space_is_ugly(map);
	return (true);
}

bool	parsing(char *map_path, t_map *map)
{
	map->map_dup = ft_calloc(1, 1);
	if (!map->map_dup)
		return (false);
	if (!valid_path(map_path))
		return (error_msg("Map: extension .cub ou chemin invalide"), false);
	if (!set_textures(map, map_path))
		return (error_msg("Textures: identifiant manquant ou invalide"), false);
	if (!set_color(map, map_path))
		return (error_msg("Couleur: format RGB invalide"), false);
	if (!check_color(map->sky_color, map->floor_color))
		return (error_msg("Couleur: valeur hors plage [0,255]"), false);
	if (!check_textures(map))
		return (error_msg("Textures: fichier introuvable ou illisible"), false);
	if (!get_map(map_path, map))
		return (error_msg("Map: lecture impossible"), false);
	return (true);
}
