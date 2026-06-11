/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:11:03 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/18 12:47:36 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char	*tmp_ptr_dest;
	unsigned char	*tmp_ptr_src;
	size_t			i;

	if (!destination && !source)
		return (NULL);
	tmp_ptr_dest = (unsigned char *)destination;
	tmp_ptr_src = (unsigned char *)source;
	i = 0;
	while (i < size)
	{
		tmp_ptr_dest[i] = tmp_ptr_src[i];
		i++;
	}
	return (tmp_ptr_dest);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int array [] = { 54, 85, 20, 63, 21 };
	int * copy = NULL;
	int length = sizeof( int ) * 5;
	   
	copy = (int *) malloc( length );
	memcpy( copy, array, length );
		
	for( length=0; length<5; length++ ) {
		printf( "%d ", copy[ length ] );
	}
	printf( "\n" );
		
	free(copy);
	
	return (0);
}*/