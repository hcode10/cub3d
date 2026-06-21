/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:36:24 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/14 21:47:23 by dcasadio         ###   ########.fr       */
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
	
	printf("Player count : %ld\n", flood->player_count);
}

static void	flood_fill(char **map_copy, int y, int x, t_flood *flood)
{
	if (y < 0 || x < 0 || !map_copy[y] || !map_copy[y][x])
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	check_cell(map_copy, y, x, flood);
	map_copy[y][x] = 'V';
	flood_fill(map_copy, y + 1, x, flood);
	flood_fill(map_copy, y - 1, x, flood);
	flood_fill(map_copy, y, x + 1, flood);
	flood_fill(map_copy, y, x - 1, flood);

	aff_map(map_copy);
}

static int	check_flood_result(t_flood *flood, t_map *game)
{
	(void)game;
	if (flood->player_count > 1 || flood->player_count == 0)
	{
		ft_putstr_fd("Pas ou trop de player sur la map !\n", 0);
		return (-1);
	}
	return (0);
}

int	is_map_solvable(t_map *game)
{
	char	**map_copy;
	t_flood	flood;

	map_copy = copy_map(game->map);
	if (!map_copy)
		return (-1);
	flood.player_count = 0;
	flood_fill(map_copy, game->player_y, game->player_x, &flood);
	free_map(map_copy);
	return (check_flood_result(&flood, game));
}
