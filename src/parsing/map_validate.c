/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/04 17:36:15 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../includes/parsing.h"

static void	check_player_collect(t_map *game, int i, int j)
{
	int	pos;

	pos = game->map[i][j];
	if (pos == 'S' || pos == 'N' || pos == 'W' || pos == 'E')
	{
		//printf("Player ok pos (%c) : x = %d y = %d\n", pos, j, i);
		game->p_pos.y = (double)i + 0.5;
		game->p_pos.x = (double)j + 0.5;
	}
}

int	validate_map_chars(t_map *game)
{
	int		i;
	int		j;
	char	*valid_chars;

	i = 0;
	valid_chars = "10NSEW \n";
	game->p_pos.x = 0;
	game->p_pos.y = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			//printf("i : %d j = %d carac = +%c+\n", i, j, game->map[i][j]);
			if (!ft_strchr(valid_chars, game->map[i][j]))
			{
				return (-1);
			}
			check_player_collect(game, i, j);
			j++;
		}
		i++;
	}
	if (game->p_pos.x == 0 || game->p_pos.y == 0)
		return (-1);
	return (0);
}

int	validate_map_walls(t_map *game)
{
	size_t	i;
	size_t	last_line;

	last_line = 0;
	while (game->map[last_line])
		last_line++;
	last_line--;
	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[last_line][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
