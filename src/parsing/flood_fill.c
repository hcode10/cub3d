/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:36:24 by dcasadio          #+#    #+#             */
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
}
