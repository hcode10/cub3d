/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:42:16 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/20 16:15:26 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	sub_size;
	size_t	i;

	i = 0;
	sub_size = ft_strlen(s)-start;
	if (len < sub_size)
		sub_size = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	new_str = ft_calloc(sub_size + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	while (s[start] && i < len)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	return (new_str);
}
/*#include <stdio.h>
int	main(void)
{
	char *result = ft_substr("tripouille", 100, 1);
	if (!result)
		return (0);
	char *empty = (char *)"";
	int check = ft_strncmp(result, empty, 2);
	printf("R1 : %d$\n", check);
	if (result)
		printf("R2 : %zu$\n", ft_strlen(result));
}*/
