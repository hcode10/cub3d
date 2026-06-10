/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:15:18 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:31:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int start = 0;

	int	re_my_eof = ft_tolower(EOF);
	int	re_eof = tolower(EOF);

	printf("Return ft_tolower : %d\n", re_my_eof);
	printf("Return tolower    : %d\n", re_eof);

	if (re_my_eof != re_eof)
	{
		printf("Difference ici ATTENTION !!!!!\n");
		printf("Valeur de comparaison : %d\n", start);
	}

	while (start < 123)
	{
		int my_result = ft_tolower(start);
		int result = tolower(start);

		printf("Return ft_tolower : %d\n", my_result);
		printf("Return tolower    : %d\n", result);

		if (my_result != result)
		{
			printf("Difference ici ATTENTION !!!!!\n");

			printf("Valeur de comparaison : %d\n", start);
		}
		start++;
	}
}*/