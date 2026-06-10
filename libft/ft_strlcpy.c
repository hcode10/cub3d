/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:04:15 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:30:15 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (src_len > i)
		return (src_len);
	return (i);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
int	main(void)
{
	char *str  = "coucou";
	int size_str = 10;
	char *dest = NULL;
	char *dest2 = NULL;
	
	dest  = (char *) malloc(size_str * sizeof(char));
	dest2 = (char *) malloc(size_str * sizeof(char));

	memset(dest,  'A', size_str);
	memset(dest2, 'A', size_str);

	printf("Retour FT : %zu\n", ft_strlcpy(dest, str, -1));
	printf("Retour    : %zu\n", strlcpy(dest2, str, -1));

	printf("Dest  is %s^\n", dest);
	printf("Dest2 is %s^\n", dest2);

	free(dest);
	free(dest2);
}*/