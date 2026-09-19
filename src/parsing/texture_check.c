/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	valid_path(char *map_path)
{
	size_t	len;

	if (!map_path)
		return (false);
	len = ft_strlen(map_path);
	if (len < 5)
		return (false);
	if (ft_strncmp(map_path + len - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

/**
 * @brief open() reussit sur un dossier : on tente une lecture d'un octet,
 * qui echoue avec EISDIR, pour n'accepter qu'un vrai fichier lisible.
 */
bool	is_readable_file(char *path)
{
	char	buf[1];
	int		fd;
	int		ret;

	if (!path || !path[0])
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	ret = read(fd, buf, 1);
	close(fd);
	return (ret > 0);
}

bool	is_readable_xpm(char *path)
{
	size_t	len;

	if (!path)
		return (false);
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (false);
	return (is_readable_file(path));
}

bool	check_textures(t_map *map)
{
	if (!is_readable_xpm(map->texture_no))
		return (false);
	if (!is_readable_xpm(map->texture_so))
		return (false);
	if (!is_readable_xpm(map->texture_we))
		return (false);
	if (!is_readable_xpm(map->texture_ea))
		return (false);
	return (true);
}
