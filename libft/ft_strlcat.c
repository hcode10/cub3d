/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:02:41 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:30:10 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t finalsize)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	min;
	size_t	i;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst > finalsize)
		min = finalsize;
	else
		min = size_dst;
	if (finalsize > size_dst)
	{
		i = 0;
		while (src[i] && (size_dst + i < finalsize -1))
		{
			dst[size_dst + i] = src[i];
			i++;
		}
		dst[size_dst + i] = '\0';
	}
	return (size_src + min);
}

/*#include <bsd/string.h>
int main(void)
{
 size_t taille = 17;
char dest[30];
char * src = (char *)"AAAAAAAAA";
char dest2[30];

memset(dest, 'C', 15);
memset(dest2, 'C', 15);
 
printf("Chaine 1    : %s\n", dest);
printf("Chaine 2    : %s\n", src);

printf("\n");

printf("Taille de SIZE : %zu\n", taille);

printf("STRLCAT renvoie : %zu\n", strlcat(dest, src, taille));
printf("FT_STRLCAT renvoie : %zu\n", ft_strlcat(dest2, src, taille));

printf("\n");
 

printf("Chaine S1 apres STRLCAT      : %s\n", dest);
printf("Chaine FT_S1 apres FT_STRLCAT: %s\n", dest2);

//printf("Result    : %i\n", !strcmp(dest,  "CCCCCCCCCCCCCCCA"));
//printf("Result FT : %i\n", !strcmp(dest2, "CCCCCCCCCCCCCCCA"));
										  
printf("\n");

printf("Taille de S1 apres STRLCAT : %lu\n", ft_strlen(dest));
printf("Taille de FT_S1 apres STRLCAT : %lu\n", ft_strlen(dest2));

return 0;
}*/