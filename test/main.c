/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:52:59 by coressor          #+#    #+#             */
/*   Updated: 2026/06/12 09:39:58 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/window.h"

int main()
{
	t_window *win;

	win = init_window();
	if(!win)
	{
		printf("Init window failed");
		return (-1);
	}
	mlx_loop(win->mlx);
	free_window(win);
	return (0);
}
