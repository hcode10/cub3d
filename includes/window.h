/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:41:56 by coressor          #+#    #+#             */
/*   Updated: 2026/07/07 17:29:48 by coressor         ###   ########.fr       */
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

# ifdef __APPLE__
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

typedef struct s_imag
{
	int		bitspp;
	int		endian;	
	int		line_len;
	void	*walls;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		no_h;
	int		no_w;
	int		so_h;
	int		so_w;
	int		we_h;
	int		we_w;
	int		ea_h;
	int		ea_w;
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
int		handle_close(t_map *map);
int		handle_keypress(int keycode, t_map *map);

// ----- ceilnfloor

int		create_back(t_window *w, t_imag *img);
int		draw_back(t_window *win);

// ------ img

void	*free_img(t_imag *img, void *mlx);
void	*init_img(t_imag *img, t_window *win, t_map *map);

#endif
