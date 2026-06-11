/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:45:33 by coressor          #+#    #+#             */
/*   Updated: 2026/03/30 22:28:31 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;

	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (ft_strlen((char *)&s[start]) < len)
		sublen = ft_strlen((char *)&s[start]);
	else
		sublen = len;
	sub = ft_calloc(sublen + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], sublen + 1);
	return (sub);
}
