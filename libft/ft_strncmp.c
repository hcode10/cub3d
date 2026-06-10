/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:06:53 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/20 16:16:10 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	l;

	l = 0;
	while (l < length && (second[l] != '\0' || first[l] != '\0'))
	{
		if ((unsigned char)first[l] != (unsigned char)second[l])
		{
			if ((unsigned char)first[l] > (unsigned char)second[l])
			{
				return (1);
			}
			else
			{
				return (-1);
			}
		}
		l++;
	}
	return (0);
}

/*#include <string.h>
*#include <stdio.h>
int	main(void)
{
	int my_result = ft_strncmp("abcd", "abcd", 25);
	int	result    = strncmp("abcd", "abcd", 25);

	printf("ft_strncmp : %d\n", my_result);
	printf("strncmp    : %d\n", result);
}*/
