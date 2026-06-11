/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:55:23 by dcasadio          #+#    #+#             */
/*   Updated: 2025/11/19 13:29:30 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i])
			{
				i++;
				if (str[i] == c)
					break ;
			}
		}
		else
			i++;
	}
	return (words);
}

static void	free_all(char **sl, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(sl[i]);
		i++;
	}
	free(sl);
}

static char	*alloc_word(char const *s, size_t start, size_t end)
{
	char	*word;

	word = ft_calloc((end - start) + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, (end - start) + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	index;
	char	**sl;

	i = -1;
	index = 0;
	sl = ft_calloc(count_words((char *)s, c) + 1, sizeof(char *));
	if (!sl)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			sl[index++] = alloc_word(s, start, i--);
			if (!sl[index - 1])
				return (free_all(sl, index - 1), NULL);
		}
	}
	return (sl);
}

/*#include <stdio.h>
int	main(void)
{
	char *s = "split  ||this|for|me|||||!|";
    char **result = ft_split(s, '|');
 
	int index = 0;
	while (result[index])
	{
		printf("arr[%d] = $%s$\n", index, result[index]);
		index++;
	}
    free(result);
        
	return (0);
	//print_index(str);
}*/
