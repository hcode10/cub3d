/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:05:37 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:30:07 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;
	char	*final_string;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	i = 0;
	final_string = (char *)malloc(sizeof(char) * (s1_size + s2_size) + 1);
	if (!final_string)
		return (NULL);
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		final_string[s1_size + i] = s2[i];
		i++;
	}
	final_string[s1_size + i] = '\0';
	return (final_string);
}

/*#include <stdio.h>
int	main(void)
{
	printf("result : %s", ft_strjoin("Salut ", "tout"));
	return (0);
}*/