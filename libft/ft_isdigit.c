/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:58:37 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 12:01:13 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	test_chars[] = {'0', '5', '9', 'A', 'z', '!', ' ', '\n'};
	int	i;
	int	size;

	i = 0;
	size = sizeof(test_chars) / sizeof(test_chars[0]);
	while (i < size)
	{
		int	my_result = (ft_isdigit(test_chars[i]) != 0);
		int	sys_result = (isdigit(test_chars[i]) != 0);

		printf("Caractère: '%c' (%d)\n",
			(test_chars[i] >= 32 && test_chars[i] <= 126) ? test_chars[i] : '?',
			test_chars[i]);
		printf("  ft_isdigit : %d\n", my_result);
		printf("  isdigit    : %d\n", sys_result);

		if (my_result != sys_result)
			printf("  ⚠️  Résultat différent !\n");
		printf("\n");
		i++;
	}
	return (0);
}*/
