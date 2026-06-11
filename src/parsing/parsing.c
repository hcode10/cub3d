/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:55 by dcasadio          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/21 16:34:13 by coressor         ###   ########.fr       */
=======
/*   Updated: 2026/06/11 18:07:40 by dcasadio         ###   ########.fr       */
>>>>>>> b80446b (Ajout des fonction set et check)
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static bool	valid_path(char *map_path)
{
	char	*ext;

	ext = map_path + (ft_strlen(map_path) - 4);
	printf("ext = %s\n", ext);
	if (ft_strncmp(ext, ".cub", 4) != 0)
	{
		ft_putstr_fd("Erreur : Veuillez verifier le chemin de map fourni !", 1);
		return (false);
	}
	return (true);
}

static bool	check_textures(t_map *map)
{
	//changer pour open access interdit
	if (!access(map->texture_ea, F_OK) == 0)
		return (false);
	if (!access(map->texture_no, F_OK) == 0)
		return (false);
	if (!access(map->texture_so, F_OK) == 0)
		return (false);
	if (!access(map->texture_we, F_OK) == 0)
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
	printf("fd = %d\n", fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		splited = ft_split(line, ' ');
		if (ft_strncmp("NO", splited[0], 2) == 0)
			map->texture_no = ft_strtrim(splited[1], "\n");
		else if (ft_strncmp("SO", splited[0], 2) == 0)
			map->texture_so = ft_strtrim(splited[1], "\n");
		else if (ft_strncmp("WE", splited[0], 2) == 0)
			map->texture_we = ft_strtrim(splited[1], "\n");
		else if (ft_strncmp("EA", splited[0], 2) == 0)
			map->texture_ea = ft_strtrim(splited[1], "\n");
		free(splited);
	}
	close(fd);
	return (false);
}

bool	set_color(t_map *map, char *map_path)
{
	char	*line;
	char	**splited;
	char	**color_split;
	int		fd;

	fd = open(map_path, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		splited = ft_split(line, ' ');
		if (ft_strncmp("F", splited[0], 1) == 0)
		{
			color_split = ft_split(splited[1], ',');
			map->floor_color[0] = ft_atoi(color_split[0]);
			map->floor_color[1] = ft_atoi(color_split[1]);
			map->floor_color[2] = ft_atoi(color_split[2]);
		}
		else if (ft_strncmp("C", splited[0], 1) == 0)
		{
			color_split = ft_split(splited[1], ',');
			map->sky_color[0] = ft_atoi(color_split[0]);
			map->sky_color[1] = ft_atoi(color_split[1]);
			map->sky_color[2] = ft_atoi(color_split[2]);
		}
		free(splited);
	}
	close(fd);
	return (false);
}

bool	parsing(char *map_path, t_map *map)
{
	if (!valid_path(map_path))
		return (false);
	set_textures(map, map_path);
	set_color(map, map_path);

	if (!check_color(map->sky_color, map->floor_color))
		return (perror("RGB : Valeurs hors plage (0, 255)"), false);

	if (!check_textures(map))
		return (perror("Veuillez verifier le chemin des textures !"), false);
	return (true);
}
