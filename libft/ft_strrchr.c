/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:48:02 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 17:01:42 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int	i;

	i = ft_strlen(str);
	if (searchedChar == '\0')
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)searchedChar)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/*#include <stdlib.h>
#include <string.h>
int main(void)
{
	const char * source = "tripouille";
    char * destination;
    int length = strlen(source);
    

    destination = (char *) malloc(sizeof(char) * (length+1));
    strcpy(destination, source);
        
    printf("Return    : %s^\n", strrchr(destination, 0));
	printf("Return FT : %s^\n", ft_strrchr(destination, 0));
        
    free(destination);
    
    return 0;
}*/