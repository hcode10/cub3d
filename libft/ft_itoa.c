/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:42:33 by coressor          #+#    #+#             */
/*   Updated: 2025/11/12 09:28:05 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_len(int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
		count++;
	while (nb / 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nb;
	int		sign;

	if (!n)
		return (ft_strdup("0"));
	sign = 1;
	len = nb_len(n);
	nb = ft_calloc(len + 1, sizeof(char));
	if (!nb)
		return (NULL);
	ft_bzero(nb, len + 1);
	if (n < 0)
	{
		sign *= -1;
		*nb = '-';
	}
	while (n)
	{
		nb[--len] = ((n % 10) * sign) + 48;
		n /= 10;
	}
	return (nb);
}
