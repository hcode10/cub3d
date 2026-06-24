/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/14 20:46:28 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	space_only(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	add_map_line(t_map *map, char *line)
{
	size_t	n;
	size_t	i;
	char	**new;

	n = 0;
	while (map->map && map->map[n])
		n++;
	new = ft_calloc(n + 2, sizeof(char *));
	if (!new)
		return (false);
	i = 0;
	while (i < n)
	{
		new[i] = map->map[i];
		i++;
	}
	new[n] = ft_strtrim(line, "\n");
	if (!new[n])
		return (free(new), false);
	free(map->map);
	map->map = new;
	return (true);
}

void	normalize_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '1';
			j++;
		}
		i++;
	}
}
