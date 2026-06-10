/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:12:48 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:27:38 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int start = 0;

	while (start < 300)
	{
		int my_result = ft_isascii(start);
		int result = isascii(start);

		printf("Return ft_isacii : %d\n", my_result);
		printf("Return isascii   : %d\n", result);

		if (my_result != result)
		{
			printf("Difference ici ATTENTION !!!!!\n");

			printf("Valeur de comparaison : %d\n", start);
		}
		start++;
	}
}*/
