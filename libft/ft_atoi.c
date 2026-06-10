/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:58:47 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/20 17:08:23 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (src[i] && (src[i] == ' ' || (src[i] >= 9 && src[i] <= 13)))
		i++;
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			sign = -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		result = result * 10 + (src[i] - '0');
		i++;
	}
	return (result * sign);
}

/*#include <stdio.h>
int main(void)
{
	printf("atoi : %d\n", atoi("-12"));
	printf("ft_atoi : %d\n", ft_atoi("-12"));
}*/