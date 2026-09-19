/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:00:00 by dcasadio          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	valid_component(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (false);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (i <= 3);
}

int	count_commas(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == ',')
			n++;
		i++;
	}
	return (n);
}

bool	fill_rgb(int *dst, char **rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!valid_component(rgb[i]))
			return (false);
		dst[i] = ft_atoi(rgb[i]);
		i++;
	}
	return (true);
}
