/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:12:07 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 12:41:34 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*re;
	size_t	result;

	result = nmemb * size;
	if (size != 0 && (result / size) != nmemb)
		return (NULL);
	re = malloc(nmemb * size);
	if (!re)
		return (NULL);
	ft_bzero(re, nmemb * size);
	return (re);
}

/*#include <string.h>
int    main(void)
{
	void *p1;
	void *p2;
	void *p3;
	void *p4;

	printf("=== Test 7: ft_calloc(0, 5) ===\n");
	p1 = ft_calloc(0, 5);
	p2 = calloc(0, 5);
	printf("ft_calloc -> %p | calloc -> %p\n", p1, p2);

	if (p1)
	{
		memset(p1, 0xAA, 1); // doit être allouable sans segfault
		free(p1);
		printf("✅ p1 est allouable et libérable\n");
	}
	else
		printf("❌ p1 est NULL\n");

	if (p2)
	{
		memset(p2, 0xAA, 1);
		free(p2);
		printf("✅ p2 est allouable et libérable\n");
	}
	else
		printf("❌ p2 est NULL\n");

	printf("\n=== Test 10: ft_calloc(5, 0) ===\n");
	p3 = ft_calloc(5, 0);
	p4 = calloc(5, 0);
	printf("ft_calloc -> %p | calloc -> %p\n", p3, p4);

	if (p3)
	{
		memset(p3, 0xBB, 1);
		free(p3);
		printf("✅ p3 est allouable et libérable\n");
	}
	else
		printf("❌ p3 est NULL\n");

	if (p4)
	{
		memset(p4, 0xBB, 1);
		free(p4);
		printf("✅ p4 est allouable et libérable\n");
	}
	else
		printf("❌ p4 est NULL\n");

	return (0);
}*/

/*int	main(void)
{
	void * p = ft_calloc(5, 0);
	void *p2 = calloc(5, 0);

	printf("p  addr : %p\n", p);
	printf("p2 addr : %p\n", p2);
	
	free(p);
	free(p2);
}*/

/*int main() {
	
	int i;
	int *pointer  = (int *) calloc(INT_NUMBER, sizeof(int));
	int *pointer2 = (int *) ft_calloc(INT_NUMBER, sizeof(int));

	assert( pointer != NULL );


	for ( i=0; i<INT_NUMBER-1; i++ ) {
		pointer[i] = i;
	}

	printf("calloc    : ");
	for (i=0; i<INT_NUMBER; i++ ) {
		printf( "%d ", pointer[i] );
	}
	printf( "\n" );

	for ( i=0; i<INT_NUMBER-1; i++ ) {
		pointer2[i] = i;
	}

	printf("ft_calloc : ");
	for (i=0; i<INT_NUMBER; i++ ) {
		printf( "%d ", pointer2[i] );
	}
	printf( "\n" );

	free(pointer);
	free(pointer2);

	return 0;
}*/