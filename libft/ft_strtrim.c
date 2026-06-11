/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:05:20 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 18:27:30 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_from(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*trim;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)s1);
	while (is_from((char)s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (is_from((char)s1[len - 1], set))
		len--;
	trim = ft_calloc(len - i + 1, sizeof(char));
	if (!trim)
		return (NULL);
	ft_bzero(trim, len - i + 1);
	ft_strlcpy(trim, &s1[i], len - i + 1);
	return (trim);
}
