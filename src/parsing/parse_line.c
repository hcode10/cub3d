/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief Nettoie une ligne d'identifiant : retire les bords blancs et
 * remplace les tabulations internes par des espaces pour que ft_split
 * decoupe correctement. Ne sert jamais sur les lignes de la carte.
 */
char	*clean_line(char *line)
{
	char	*out;
	int		i;

	if (!line)
		return (NULL);
	out = ft_strtrim(line, " \t\n\r");
	if (!out)
		return (NULL);
	i = 0;
	while (out[i])
	{
		if (out[i] == '\t')
			out[i] = ' ';
		i++;
	}
	return (out);
}

/**
 * @brief Vide le reste du descripteur pour liberer le buffer statique
 * de get_next_line avant de fermer le fichier.
 */
void	drain_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	match_element(char *clean)
{
	if (ft_strncmp("NO ", clean, 3) == 0 || ft_strncmp("SO ", clean, 3) == 0
		|| ft_strncmp("WE ", clean, 3) == 0 || ft_strncmp("EA ", clean, 3) == 0
		|| ft_strncmp("F ", clean, 2) == 0 || ft_strncmp("C ", clean, 2) == 0)
		return (1);
	return (0);
}
