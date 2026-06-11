/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:37:17 by coressor          #+#    #+#             */
/*   Updated: 2026/04/26 15:39:07 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **start)
{
	char	**tmp;

	tmp = start;
	if (*start)
	{
		while (*start)
		{
			free(*start);
			start++;
		}
	}
	if (tmp)
		free(tmp);
}
