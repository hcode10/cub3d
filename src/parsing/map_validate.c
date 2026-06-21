/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/21 14:41:20 by dcasadio         ###   ########.fr       */
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
		game->p_pos.y = (double)i;
		game->p_pos.x = (double)j;
	}
}

bool	validate_map_chars(t_map *game)
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
			if (!ft_strchr(valid_chars, game->map[i][j]))
				return (error_msg("Map: caractere invalide"), false);
			check_player_collect(game, i, j);
			j++;
		}
		i++;
	}
	if (game->p_pos.x == 0 || game->p_pos.y == 0)
		return (error_msg("Map: joueur absent ou mal place"), false);
	return (true);
}
