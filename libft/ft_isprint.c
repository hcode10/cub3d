/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:12:48 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:27:52 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
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
		int my_result = ft_isprint(start);
		int result = isprint(start);

		printf("Return ft_isprint : %d\n", my_result);
		printf("Return isprint    : %d\n", result);

		if (result > 0)
			result = 1;
		if (my_result != result)
		{
			printf("Difference ici ATTENTION !!!!!\n");

			printf("Valeur de comparaison : %d\n", start);
		}
		start++;
	}
}*/
