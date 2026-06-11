/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:24:31 by coressor          #+#    #+#             */
/*   Updated: 2025/11/20 13:24:56 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joinstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*s1 = 0;
	}
	joinstr = malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1);
	if (!joinstr)
		return (free(s1), NULL);
	while (s1[j])
		joinstr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		joinstr[i++] = s2[j++];
	joinstr[i] = 0;
	free(s1);
	return (joinstr);
}
