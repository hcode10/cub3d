/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:54:45 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/20 16:55:46 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (&s[i]));
		++i;
	}
}

/*void
iter(unsigned int i, char * s) {
	*s += i;
}

int	main(void)
{
	char s[] = "0000000000";
	ft_striteri("", iter);
	printf("Result : %s\n", s);
	return (0);
}*/