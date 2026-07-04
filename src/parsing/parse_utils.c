/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:01:12 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/14 20:46:28 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	count_tabs(char **tab)
{
	size_t	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

void	free_tabs(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_struct(t_map *map)
{
	if (map->map)
		free_split(map->map);
	if (map->map_dup)
		free_map(map->map_dup);
	if (map->texture_ea)
		free(map->texture_ea);
	if (map->texture_no)
		free(map->texture_no);
	if (map->texture_so)
		free(map->texture_so);
	if (map->texture_we)
		free(map->texture_we);
}

int	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	return (1);
}

char	*no_spaces(char *str)
{
	char	*result;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	result = ft_calloc(1, ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
