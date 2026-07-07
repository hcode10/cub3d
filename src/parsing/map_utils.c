/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/07/07 19:11:29 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **map)
{
	int		i;
	int		map_line;
	char	**map_copy;

	map_line = 0;
	while (map[map_line])
		map_line++;
	map_copy = malloc(sizeof(char *) * (map_line + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i <= map_line)
		map_copy[i++] = NULL;
	map_line = 0;
	while (map[map_line])
	{
		map_copy[map_line] = ft_strdup(map[map_line]);
		if (!map_copy[map_line])
			return (free_map(map_copy), NULL);
		map_line++;
	}
	return (map_copy);
}
