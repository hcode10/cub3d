/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:36:24 by dcasadio          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/06/22 17:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	cell_state(char **m, int y, int x)
{
	if (y < 0 || x < 0 || !m[y])
		return (-1);
	if (x >= (int)ft_strlen(m[y]) || m[y][x] == ' ')
		return (-1);
	if (m[y][x] == '1' || m[y][x] == 'V')
		return (0);
	return (1);
}

static long	push4(int *sa, long top, int y, int x)
{
	sa[top * 2] = y + 1;
	sa[top * 2 + 1] = x;
	top++;
	sa[top * 2] = y - 1;
	sa[top * 2 + 1] = x;
	top++;
	sa[top * 2] = y;
	sa[top * 2 + 1] = x + 1;
	top++;
	sa[top * 2] = y;
	sa[top * 2 + 1] = x - 1;
	top++;
	return (top);
}

static void	flood_iter(char **m, t_flood *fl, int *sa, int *start)
{
	long	top;
	int		y;
	int		x;
	int		s;

	sa[0] = start[0];
	sa[1] = start[1];
	top = 1;
	while (top > 0)
	{
		top--;
		y = sa[top * 2];
		x = sa[top * 2 + 1];
		s = cell_state(m, y, x);
		if (s < 0)
			fl->escaped = true;
		if (s <= 0)
			continue ;
		if (ft_strchr("NSEW", m[y][x]))
			fl->player_count++;
		m[y][x] = 'V';
		top = push4(sa, top, y, x);
	}
}

static long	stack_cap(char **m)
{
	long	cells;
	int		i;

	cells = 0;
	i = 0;
	while (m[i])
	{
		cells += ft_strlen(m[i]);
		i++;
	}
	return (4 * cells + 8);
}

bool	is_map_solvable(t_map *game)
{
	char	**m;
	int		*sa;
	int		start[2];
	t_flood	fl;

	m = copy_map(game->map_dup);
	if (!m)
		return (false);
	sa = malloc(sizeof(int) * stack_cap(m) * 2);
	if (!sa)
		return (free_map(m), false);
	start[0] = (int)game->p_pos.y;
	start[1] = (int)game->p_pos.x;
	fl.player_count = 0;
	fl.escaped = false;
	flood_iter(m, &fl, sa, start);
	free(sa);
	free_map(m);
	dbg_flood(&fl);
	if (fl.player_count != 1)
		return (error_msg("Map: nombre de joueurs invalide"), false);
	if (fl.escaped)
		return (error_msg("Map: non fermee par des murs"), false);
	return (true);
=======
/*   Updated: 2026/06/14 21:47:23 by dcasadio         ###   ########.fr       */
=======
/*   Updated: 2026/06/21 15:09:56 by dcasadio         ###   ########.fr       */
>>>>>>> 6a8cdfa (On n'est pas mal la)
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
	
	//printf("Player count : %ld\n", flood->player_count);
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

	//aff_map(map_copy);
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
	flood_fill(map_copy, game->p_pos.y, game->p_pos.x, &flood);
	free_map(map_copy);
	return (check_flood_result(&flood, game));
>>>>>>> b5d6c59 (Git e merde)
}
