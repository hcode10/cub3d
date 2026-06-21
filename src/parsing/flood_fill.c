/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:36:24 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/21 15:09:56 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../includes/parsing.h"

static void	check_cell(char **map_copy, int y, int x, t_flood *flood)
{
	size_t pos;

	pos = map_copy[y][x];
	if (pos == 'S' || pos == 'N' || pos == 'W' || pos == 'E')
		flood->player_count++;
}

static void	flood_fill(char **map_copy, int y, int x, t_flood *flood)
{
	if (y < 0 || x < 0 || !map_copy[y])      // sorti par le haut/bas/gauche
      return (flood->escaped = true, (void)0);
  	if (!map_copy[y][x] || map_copy[y][x] == ' ')  // fin de ligne (ragged) ou espace = ouvert
      return (flood->escaped = true, (void)0);
  	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
      return ;
	check_cell(map_copy, y, x, flood);
	map_copy[y][x] = 'V';
	flood_fill(map_copy, y + 1, x, flood);
	flood_fill(map_copy, y - 1, x, flood);
	flood_fill(map_copy, y, x + 1, flood);
	flood_fill(map_copy, y, x - 1, flood);
}

bool	check_flood_result(t_flood *flood, t_map *game)
{
	(void)game;
	if (flood->player_count > 1 || flood->player_count == 0)
		return (error_msg("Map: nombre de joueurs invalide"), false);
	if (flood->escaped)
		return (error_msg("Map: non fermee par des murs"), false);
	return (true);
}

bool	is_map_solvable(t_map *game)
{
	char	**map_copy;
	t_flood	flood;

	map_copy = copy_map(game->map);
	if (!map_copy)
		return (false);
	flood.player_count = 0;
	flood.escaped = false;
	flood_fill(map_copy, game->p_pos.y, game->p_pos.x, &flood);
	free_map(map_copy);
	return (check_flood_result(&flood, game));
}
