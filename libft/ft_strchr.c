/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:00:28 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 16:57:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)searchedChar)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)searchedChar == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char * str = "teste";
	
	char *res = ft_strchr(str, 1024);
	char *res_std = strchr(str, 1024);

    printf("Return FT : $%s$\n", res);
	printf("Return : $%s$\n", res_std);
    
    return 0;
}*/