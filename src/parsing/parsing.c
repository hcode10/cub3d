/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:55 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	all_textures_set(t_map *map)
{
	return (map->texture_no && map->texture_so
		&& map->texture_we && map->texture_ea);
}

bool	parsing(char *map_path, t_map *map)
{
	if (!valid_path(map_path))
		return (error_msg("Map: extension .cub attendue"), false);
	if (!is_readable_file(map_path))
		return (error_msg("Map: fichier introuvable, vide ou illisible"),
			false);
	if (!set_textures(map, map_path))
		return (error_msg("Textures: identifiant manquant ou duplique"),
			false);
	if (!all_textures_set(map))
		return (error_msg("Textures: NO, SO, WE ou EA manquante"), false);
	if (!check_textures(map))
		return (error_msg("Textures: fichier .xpm introuvable"), false);
	if (!set_color(map, map_path))
		return (error_msg("Couleur: format RGB invalide ou duplique"), false);
	if (!map->f_set || !map->c_set)
		return (error_msg("Couleur: F ou C manquante"), false);
	if (!check_color(map->sky_color, map->floor_color))
		return (error_msg("Couleur: valeur hors plage [0,255]"), false);
	if (!get_map(map_path, map))
		return (error_msg("Map: grille absente ou mal formee"), false);
	return (true);
}
