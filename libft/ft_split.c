/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:54:21 by coressor          #+#    #+#             */
/*   Updated: 2026/06/21 14:25:42 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			i++;
		}
		else if (*s == c && flag)
			flag = 0;
		s++;
	}
	return (i);
}

int	len_word(char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

const char	*next_occ(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return (s);
}

void	free_split(char **start)
{
	char	**tmp;

	tmp = start;
	if (*start)
	{
		while (*start)
		{
			free(*start);
			start++;
		}
	}
	free(tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	**start;

	if (!s)
		return (NULL);
	split = ft_calloc(count_word((char *)s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	start = split;
	while (*s)
	{
		if (len_word((char *)s, c))
		{
			*split = ft_calloc(len_word((char *)s, c) + 1, sizeof(char));
			if (!(*split))
				return (free_split(start), NULL);
			ft_strlcpy(*split, (char *)s, len_word((char *)s, c) + 1);
			split++;
			s += len_word((char *)s, c);
		}
		else
			s = next_occ(s, c);
	}
	return (start);
}
