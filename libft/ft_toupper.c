/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:15:18 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:31:15 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int start = 0;

	int	re_my_eof = ft_toupper(EOF);
	int	re_eof = toupper(EOF);

	printf("Return ft_toupper : %d\n", re_my_eof);
	printf("Return toupper    : %d\n", re_eof);

	if (re_my_eof != re_eof)
	{
		printf("Difference ici ATTENTION !!!!!\n");
		printf("Valeur de comparaison : %d\n", start);
	}

	while (start < 123)
	{
		int my_result = ft_toupper(start);
		int result = toupper(start);

		printf("Return ft_toupper : %d\n", my_result);
		printf("Return toupper    : %d\n", result);

		if (my_result != result)
		{
			printf("Difference ici ATTENTION !!!!!\n");

			printf("Valeur de comparaison : %d\n", start);
		}
		start++;
	}
}*/