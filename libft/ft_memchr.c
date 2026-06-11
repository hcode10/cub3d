/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:40:37 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:28:47 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*tmp_ptr;
	size_t			i;

	tmp_ptr = (unsigned char *)memoryBlock;
	i = 0;
	while (i < size)
	{
		if (tmp_ptr[i] == (unsigned char)searchedChar)
			return (&tmp_ptr[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 'A' };
    const unsigned int size = 10;


    void * found = ft_memchr( data, 'A' + 256, size );
    printf( "A is %s\n", ( found != NULL ? "found" : "not found" ) );

    found = ft_memchr( data, 50, size );
    printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
    if ( found != NULL ) {
        printf( "La valeur à la position calculée est %c\n", *((char *) found) );
    }

    return EXIT_SUCCESS;
}*/