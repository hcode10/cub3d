/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:12:22 by coressor          #+#    #+#             */
/*   Updated: 2026/06/14 13:12:58 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joinstr;
	size_t	totallen;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2[0])
		return (s2);
	if (!s2 && s1[0])
		return (s1);
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
