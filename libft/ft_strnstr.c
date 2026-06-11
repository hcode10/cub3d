/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:20:20 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 18:26:50 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	if (!*little)
		return ((char *)big);
	y = 0;
	if (!len)
		return (NULL);
	while (*big)
	{
		i = 0;
		while (little[i] && little[i] == *(big + i))
			i++;
		if (little[i] == 0 && (y + i) <= len)
			return ((char *)big);
		y++;
		big++;
	}
	return (NULL);
}
