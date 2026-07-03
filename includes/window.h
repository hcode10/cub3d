/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:41:56 by coressor          #+#    #+#             */
/*   Updated: 2026/07/03 17:50:26 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "parsing.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_imag
{
	int		h;
	int		w;
	int		bitspp;
	int		endian;	
	int		line_len;
	void	*back;
	void	*walls;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_imag;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	char	*title;
	t_imag	img;
	int		sizex;
	int		sizey;
	int		ceil;
	int		floor;
}	t_window;

// ----- init_window

void	*init_window(t_map *map);
void	free_window(t_window *s_win);
// int		init_screen();

// ----- ceilnfloor

int		create_back(t_window *w, t_imag *img);
int		draw_back(t_window *win);

// ------ img

void	*free_img(t_imag *img, void *mlx);
void	*init_img(t_imag *img, t_window *win, t_map *map);

#endif
