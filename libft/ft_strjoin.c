/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:12:22 by coressor          #+#    #+#             */
/*   Updated: 2026/04/06 00:29:01 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	totallen;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	totallen = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	joinstr = ft_calloc(totallen, sizeof(char));
	if (!joinstr)
		return (NULL);
	ft_bzero(joinstr, totallen);
	while (*s1)
	{
		joinstr[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		joinstr[i] = *s2++;
		i++;
	}
	return (joinstr);
}
