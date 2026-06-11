/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:52:51 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/15 20:12:20 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	//const char	*largestring = "aaabcabcd";
	//const char	*smallstring = "a";
	char *ptr = NULL;
	char *ptr2 = NULL;
	char haystack[30] = "aaabcabcd";
	//char needle[10] = "aabc";
	//char *empty = (char*)"";

	printf("ptr adress : %p\n", ptr);
	printf("ptr2 adress : %p\n", ptr2);

	ptr  = strnstr(haystack, "cd", 8);
	ptr2 = ft_strnstr(haystack, "cd", 8);
	
	printf("Result addr    : %p$\n", ptr);
	printf("Result addr FT : %p$\n", ptr2);

	printf("Result    : %s$\n", ptr);
	printf("Result FT : %s$\n", ptr2);
	
	return (0);
}*/