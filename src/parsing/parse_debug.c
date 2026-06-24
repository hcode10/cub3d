/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/22 10:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	dbg_step(char *msg)
{
	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[36m[DBG] >> %s\033[0m\n", msg);
}

void	dbg_textures(t_map *map)
{
	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[35m[DBG] textures:\033[0m\n");
	fprintf(stderr, "        NO = [%s]\n", map->texture_no);
	fprintf(stderr, "        SO = [%s]\n", map->texture_so);
	fprintf(stderr, "        WE = [%s]\n", map->texture_we);
	fprintf(stderr, "        EA = [%s]\n", map->texture_ea);
}

void	dbg_colors(t_map *map)
{
	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[35m[DBG] colors:\033[0m\n");
	fprintf(stderr, "        F (floor) = %d,%d,%d\n", map->floor_color[0],
		map->floor_color[1], map->floor_color[2]);
	fprintf(stderr, "        C (sky)   = %d,%d,%d\n", map->sky_color[0],
		map->sky_color[1], map->sky_color[2]);
}

void	dbg_map(t_map *map)
{
	int	i;

	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[35m[DBG] map grid:\033[0m\n");
	i = 0;
	while (map->map && map->map[i])
	{
		fprintf(stderr, "        %3d |%s|\n", i, map->map[i]);
		i++;
	}
	fprintf(stderr, "        rows=%d  player(x=%.0f, y=%.0f)\n",
		i, map->p_pos.x, map->p_pos.y);
}

void	dbg_flood(t_flood *flood)
{
	if (!DEBUG)
		return ;
	fprintf(stderr, "\033[35m[DBG] flood: player_count=%zu escaped=%d\033[0m\n",
		flood->player_count, flood->escaped);
}
