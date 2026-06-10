/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:02:10 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:29:02 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_ptr_dest;
	char	*tmp_ptr_src;
	size_t	i;

	i = 0;
	tmp_ptr_src = (char *)src;
	tmp_ptr_dest = (char *)dest;
	if (tmp_ptr_dest > tmp_ptr_src)
	{
		while (n > 0)
		{
			n--;
			tmp_ptr_dest[n] = tmp_ptr_src[n];
		}
	}
	else if (tmp_ptr_dest < tmp_ptr_src)
	{
		while (i < n)
		{
			tmp_ptr_dest[i] = tmp_ptr_src[i];
			i++;
		}
	}
	return (dest);
}

/*int main(void)
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};

	char s1[] = {65, 66, 67, 68, 69, 0, 45};
	char s10[] = { 0,  0,  0,  0,  0,  0, 0};


	ft_memmove(s, s0, 7); // copier "Hello World!"
	memmove(s1, s10, 7); // copier "Hello World!"
	int i = 0;
	while (i < 7)
	{
		printf("Value : %c\n", s[i]);   
		i++;
	}
	printf("str1 = %s\n", s);
	printf("str2 = %s\n", s1);

	return 0;
}*/

/*int main(void)
{
	char str1[20] = "Hello World!";
	char str2[20];

	printf("=== Test 1 : copier simple ===\n");
	ft_memmove(str2, str1, sizeof(char) * ft_strlen(str1) + 1);
	str2[12] = '\0';
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);

	printf("\n=== Test 2 : chevauchement (début vers milieu) ===\n");
	char str3[20] = "ABCDEFGHIK";
	ft_memmove(str3 + 2, str3, 9); 
	printf("str3 = %s\n", str3); // devrait être "1212345678"

	char str4[20] = "abcdefghij";
	ft_memmove(str4, str4 + 2, 8);
	str4[8] = '\0';
	printf("str4 = %s\n", str4); // devrait être "cdefghij"

	return 0;
}*/
