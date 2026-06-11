/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:12 by coressor          #+#    #+#             */
/*   Updated: 2025/11/11 19:52:21 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (!*lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
}
