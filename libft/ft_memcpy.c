/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:10:47 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 18:20:22 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmps;
	char	*tmpd;

	tmps = (char *)src;
	tmpd = (char *)dest;
	if (!src && !dest)
		return (NULL);
	while (n)
	{
		*tmpd++ = *tmps++;
		n--;
	}
	return (dest);
}
