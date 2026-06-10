/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:55:42 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/18 12:47:29 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)pointer1;
	tmp2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size)
	{
		if (tmp1[i] != tmp2[i])
		{
			return (tmp1[i] - tmp2[i]);
		}
		i++;
	}
	return (0);
}
