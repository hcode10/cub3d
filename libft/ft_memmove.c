/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:13:33 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 18:21:05 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dest;
	tmps = (unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		tmps += n;
		tmpd += n;
		while (tmps != src)
			*--tmpd = *--tmps;
	}
	else
	{
		while (tmps != src + n)
			*tmpd++ = *tmps++;
	}
	return (dest);
}
