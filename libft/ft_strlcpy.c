/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:29:51 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 18:23:15 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char *)src);
	while (i < len && i + 1 < siz)
	{
		dst[i] = src[i];
		i++;
	}
	if (siz != 0)
		dst[i] = 0;
	return (len);
}
