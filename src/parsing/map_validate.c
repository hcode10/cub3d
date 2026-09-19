/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief Renvoie le nombre de joueurs de la ligne, ou -1 si un caractere
 * interdit s'y trouve. Memorise au passage la case de depart, centree.
 */
static int	check_line(t_map *game, size_t i)
{
	size_t	j;
	int		players;

	j = 0;
	players = 0;
	while (game->map[i][j])
	{
		if (!ft_strchr("10NSEW ", game->map[i][j]))
			return (-1);
		if (ft_strchr("NSEW", game->map[i][j]))
		{
			game->p_pos.y = (double)i + 0.5;
			game->p_pos.x = (double)j + 0.5;
			players++;
		}
		j++;
	}
	return (players);
}

bool	validate_map_chars(t_map *game)
{
	size_t	i;
	int		n;
	int		players;

	if (!game->map || !game->map[0])
		return (error_msg("Map: carte vide"), false);
	i = 0;
	players = 0;
	while (game->map[i])
	{
		n = check_line(game, i);
		if (n < 0)
			return (error_msg("Map: caractere invalide"), false);
		players += n;
		i++;
	}
	if (players == 0)
		return (error_msg("Map: aucun joueur"), false);
	if (players > 1)
		return (error_msg("Map: plusieurs joueurs"), false);
	return (true);
}
