/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:58:52 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 12:00:59 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);

int	main(void)
{
	int	test_chars[] = {'A', 'z', 'M', '9', '!', 't', ' ', '\n'};
	int	i;
	int	size;

	i = 0;
	size = sizeof(test_chars) / sizeof(test_chars[0]);
	while (i < size)
	{
		int	my_result = ft_isalpha(test_chars[i]);
		int	sys_result = isalpha(test_chars[i]);

		printf("Caractère: '%c' (%d)\n",
			(test_chars[i] >= 32 && test_chars[i] <= 126) ? test_chars[i] : '?',
			test_chars[i]);
		printf("  ft_isalpha : %d\n", my_result);
		printf("  isalpha    : %d\n", sys_result);
		if ((my_result != 0 && sys_result == 0)
			|| (my_result == 0 && sys_result != 0))
			printf("  ⚠️  Résultat différent !\n");
		printf("\n");
		i++;
	}
	return (0);
}*/
