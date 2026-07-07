/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:59:43 by coressor          #+#    #+#             */
/*   Updated: 2026/07/07 20:29:57 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
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
typedef struct s_player_pos
{
	double	x;
	double	y;
}	t_player_pos;

typedef struct s_map
{
	char			**map;
	char			**map_dup;
	t_player_pos	p_pos;
	int				floor_color[3];
	int				sky_color[3];
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	size_t			width;
	size_t			height;
}	t_map;

typedef struct s_flood
{
	size_t	player_count;
	bool	escaped;
}	t_flood;

typedef struct s_player
{
	double			plane[2];
	double			dir[2];
	t_player_pos	*p_pos;
}	t_player;

typedef struct s_game
{
	t_player		player;
	t_map			maps;
	t_window		*win;
	int				movX;
	int				movY;
	int				rot;
}	t_game;

typedef struct s_text
{
	char	*buf;
	int		bpp;
	int		line;
	int		endian;
	double	step;
	double	pos;
}	t_text;

typedef struct s_render
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		y;
	char	*buf;
	char	*px;
}	t_render;

typedef struct s_ray
{
	double	*plane;
	double	*dir;
	double	ray[2];
	double	cam;
	double	perpwall;
	double	sidedist[2];
	double	deltadist[2];
	int		side;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	double	wallx;   
	void	*tex;    
	int		tex_w;   
	int		tex_h;   
	int		texx; 
}	t_ray;

void	init_player(t_player *player, t_player_pos *p_pos, char **map);
void	init_ray(t_player *player, t_ray *ray);
void	*render_walls(t_player *player, t_window *win, t_map *map);
void	*draw_walls(t_ray *ray, t_window *win, int x);
void	put_wall_pixel(t_render *rend, t_window *w, t_text *tex, t_ray *ray);
void	choose_text(t_ray *ray, t_player *player, t_window *win);
int		init_text(t_text *tex, t_ray *ray, t_render *rend, t_window *w);
bool	parsing(char *map_path, t_map *map);
int		error_msg(char *msg);
size_t	count_tabs(char **tab);
void	free_tabs(char **tab);
void	free_struct(t_map *map);
void	free_map(char **map);
char	**copy_map(char **map);
bool	valid_path(char *map_path);
bool	check_textures(t_map *map);
bool	set_textures(t_map *map, char *map_path);
bool	check_color(int *sky_color, int *floor_color);
bool	set_color(t_map *map, char *map_path);
bool	get_map(char *map_path, t_map *map);
bool	add_map_line(t_map *map, char *line);
bool	space_only(char *str);
void	normalize_map(t_map *map);
bool	validate_map_chars(t_map *game);
bool	is_map_solvable(t_map *game);
char	*no_spaces(char *s);
int		validate_map_walls(t_map *game);
int		read_map(t_map *game);
void	set_heigth(t_map *game, int height);
int		map_count_line(void);
void	init_sideDist(t_ray *ray, t_player_pos *p_pos);
int		dda(t_ray *ray, char **map);
void	calc_render(t_window *win, t_ray *ray, t_render *rend);
void	*init_window(t_map *map);
void	free_window(t_window *s_win);
int		handle_close(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		create_back(t_window *w, t_imag *img);
int		draw_back(t_window *win);
void	*free_img(t_imag *img, void *mlx);
void	*init_img(t_imag *img, t_window *win, t_map *map);
int		handle_keyrelease(int keycode, t_game *game);
#endif
