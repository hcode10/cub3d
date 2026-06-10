/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:39:10 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:30:48 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_carac(char c, char *charset)
{
	size_t	i;

	if (c == 0)
		return (1);
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	getstartindex(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (verif_carac(s1[i], (char *)set) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static size_t	getendindex(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (verif_carac(s1[i], (char *)set) == 0)
		{
			return (i + 1);
		}
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	index_start;
	size_t	index_end;
	size_t	index_finale;

	if (!s1)
		return (NULL);
	index_start = getstartindex(s1, set);
	index_end = getendindex(s1, set);
	new_str = ft_calloc((index_end - index_start) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = index_start;
	index_finale = 0;
	while (s1[i] && i < index_end)
	{
		new_str[index_finale] = s1[i];
		i++;
		index_finale++;
	}
	new_str[index_finale] = '\0';
	return (new_str);
}

/*#include <stdio.h>
int	main(void)
{
	char *chaine = "  xxxxxxxtr888xxx  ";
	int index_start = getstartindex(chaine, " x");
	int index_end = getendindex(chaine, " x");
	printf("start : %i end : %i\n", index_start, index_end);
	printf("Result : $%s$\n", ft_strtrim(" xxxxxtripouillex   ", " x"));
	return (0);
}*/