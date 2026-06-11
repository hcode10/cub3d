/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:55:55 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 18:24:34 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	ret;

	if (!siz)
		return (ft_strlen((char *)src) + siz);
	i = ft_strlen(dst);
	ret = ft_strlen((char *)src);
	if (siz < i)
		ret += siz;
	else
		ret += i;
	while (i + 1 < siz && *src)
		dst[i++] = *src++;
	if (siz > i)
		dst[i] = '\0';
	return (ret);
}
