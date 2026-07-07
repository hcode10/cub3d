/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:55 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/07 19:31:51 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	parsing(char *map_path, t_map *map)
{
	if (!valid_path(map_path))
		return (error_msg("Map: extension .cub ou chemin invalide"), false);
	if (!set_textures(map, map_path))
		return (error_msg("Textures: identifiant manquant"), false);
	if (!set_color(map, map_path))
		return (error_msg("Couleur: format RGB invalide"), false);
	if (!check_color(map->sky_color, map->floor_color))
		return (error_msg("Couleur: valeur hors plage [0,255]"), false);
	if (!check_textures(map))
		return (error_msg("Textures: fichier introuvable"), false);
	if (!get_map(map_path, map))
		return (error_msg("Map: lecture impossible"), false);
	return (true);
}
