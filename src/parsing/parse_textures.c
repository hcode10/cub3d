/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	set_one(char **dst, char *value)
{
	if (*dst)
		return (false);
	*dst = ft_strdup(value);
	return (*dst != NULL);
}

static bool	set_one_texture(t_map *map, char **splited)
{
	if (ft_strcmp(splited[0], "NO") == 0)
		return (set_one(&map->texture_no, splited[1]));
	if (ft_strcmp(splited[0], "SO") == 0)
		return (set_one(&map->texture_so, splited[1]));
	if (ft_strcmp(splited[0], "WE") == 0)
		return (set_one(&map->texture_we, splited[1]));
	if (ft_strcmp(splited[0], "EA") == 0)
		return (set_one(&map->texture_ea, splited[1]));
	return (true);
}

bool	handle_tex_line(t_map *map, char *clean)
{
	char	**splited;
	bool	ok;

	splited = ft_split(clean, ' ');
	if (!splited)
		return (false);
	ok = true;
	if (count_tabs(splited) == 2)
		ok = set_one_texture(map, splited);
	free_tabs(splited);
	return (ok);
}
