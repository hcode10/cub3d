/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:21:44 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/20 17:07:08 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int c, size_t size)
{
	unsigned char	*tmp_ptr;
	size_t			i;

	i = 0;
	tmp_ptr = (unsigned char *)pointer;
	while (i < size)
	{
		tmp_ptr[i] = c;
		i++;
	}
	return (pointer);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int array [] = { 54, 85, 20, 63, 21 };
	size_t size = sizeof( int ) * 5;
	int length;

	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );


	ft_memset( array, 0, size );

	for( length=0; length<5; length++) {
		printf( "%c ", array[ length ] );
	}
	printf( "\n" );
	
	return 0;
}*/