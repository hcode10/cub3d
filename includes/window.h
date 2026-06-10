/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:41:56 by coressor          #+#    #+#             */
/*   Updated: 2026/06/10 17:55:55 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		sizex;
	int		sizey;
} t_window;

void	*init_window();
// int		init_screen();
void	free_window(t_window *s_win);

#endif
