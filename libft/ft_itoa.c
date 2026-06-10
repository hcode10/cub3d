/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:24:02 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/20 16:39:32 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	int_sizechar(long long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ascii_int;
	long	nbr;

	nbr = (long)n;
	len = int_sizechar(nbr);
	ascii_int = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ascii_int)
		return (NULL);
	if (nbr < 0)
	{
		ascii_int[0] = '-';
		nbr = -nbr;
	}
	ascii_int[--len] = (nbr % 10) + '0';
	while (nbr >= 10)
	{
		nbr /= 10;
		ascii_int[--len] = (nbr % 10) + '0';
	}
	return (ascii_int);
}

/*int	main(void)
{
	int	n = -4256;
	char *str;
	int i;
	
	i = 0;
	printf("$%zu$\n", int_sizechar(n));
	str = ft_itoa(n);

	while (str[i])
	{
		printf("str[%d] = $%c$\n", i, str[i]);
		i++;
	}
	
	free(str);
	return (0);
}*/
