/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	cell_state(char **m, int y, int x)
{
	if (y < 0 || x < 0 || !m[y])
		return (-1);
	if (x >= (int)ft_strlen(m[y]) || m[y][x] == ' ')
		return (-1);
	if (m[y][x] == '1' || m[y][x] == 'V')
		return (0);
	return (1);
}

long	push4(int *sa, long top, int y, int x)
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

long	stack_cap(char **m)
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
