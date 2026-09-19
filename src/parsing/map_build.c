/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	space_only(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r')
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

	n = count_tabs(map->map);
	new = ft_calloc(n + 2, sizeof(char *));
	if (!new)
		return (false);
	i = 0;
	while (i < n)
	{
		new[i] = map->map[i];
		i++;
	}
	new[n] = ft_strtrim(line, "\n\r");
	if (!new[n])
		return (free(new), false);
	free(map->map);
	map->map = new;
	return (true);
}

static size_t	max_width(char **map)
{
	size_t	i;
	size_t	max;
	size_t	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

/**
 * @brief Reecrit chaque ligne sur la meme largeur : les espaces (interieurs
 * comme ajoutes a droite) deviennent des murs. Sans ca la grille reste
 * irreguliere et le DDA lit hors des chaines les plus courtes.
 */
static char	*pad_line(char *line, size_t width)
{
	char	*new;
	size_t	i;

	new = malloc(width + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			new[i] = '1';
		else
			new[i] = line[i];
		i++;
	}
	while (i < width)
		new[i++] = '1';
	new[i] = '\0';
	return (new);
}

bool	normalize_map(t_map *map)
{
	size_t	i;
	char	*line;

	map->width = max_width(map->map);
	map->height = count_tabs(map->map);
	if (map->width == 0 || map->height == 0)
		return (false);
	i = 0;
	while (map->map[i])
	{
		line = pad_line(map->map[i], map->width);
		if (!line)
			return (false);
		free(map->map[i]);
		map->map[i] = line;
		i++;
	}
	return (true);
}
