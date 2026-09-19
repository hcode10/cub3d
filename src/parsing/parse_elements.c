/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	dispatch(t_map *map, char *clean, bool textures)
{
	if (textures)
		return (handle_tex_line(map, clean));
	return (handle_color_line(map, clean));
}

/**
 * @brief Parcourt uniquement les 6 lignes d'identifiants en tete de
 * fichier, pour ne jamais confondre une ligne de carte avec un element.
 */
static bool	scan_elements(int fd, t_map *map, bool textures)
{
	char	*line;
	char	*clean;
	int		count;
	bool	ok;

	count = 0;
	ok = true;
	line = get_next_line(fd);
	while (line && count < 6 && ok)
	{
		clean = clean_line(line);
		free(line);
		if (!clean)
			return (false);
		if (clean[0])
		{
			ok = dispatch(map, clean, textures);
			count++;
		}
		free(clean);
		line = get_next_line(fd);
	}
	free(line);
	return (ok);
}

static bool	run_scan(t_map *map, char *map_path, bool textures)
{
	int		fd;
	bool	ok;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	ok = scan_elements(fd, map, textures);
	drain_gnl(fd);
	close(fd);
	return (ok);
}

bool	set_textures(t_map *map, char *map_path)
{
	return (run_scan(map, map_path, true));
}

bool	set_color(t_map *map, char *map_path)
{
	return (run_scan(map, map_path, false));
}
