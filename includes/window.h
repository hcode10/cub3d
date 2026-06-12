/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:41:56 by coressor          #+#    #+#             */
/*   Updated: 2026/06/12 11:48:24 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;
	char	*title;
	int		sizex;
	int		sizey;
} t_window;

void	*init_window();
// int		init_screen();
void	free_window(t_window *s_win);

#endif
