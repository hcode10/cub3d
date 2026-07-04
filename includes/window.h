/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:41:56 by coressor          #+#    #+#             */
/*   Updated: 2026/07/04 20:54:47 by dcasadio         ###   ########.fr       */
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

typedef struct s_window
{
	void	*mlx;
	void	*win;
	char	*title;
	int		sizex;
	int		sizey;
	int		ceil;
	int		floor;
	int		bitspp;
	int		endian;
	void	*back;
} t_window;

// ----- init_window

void	*init_window(t_map *map);
// int		init_screen();
void	free_window(t_window *s_win);
int		handle_close(t_map *map);
int		handle_keypress(int keycode, t_map *map);

// ----- ceilnfloor

int	create_back(t_window *win);
int	draw_back(t_window *win);

#endif
