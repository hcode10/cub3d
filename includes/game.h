/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:59:43 by coressor          #+#    #+#             */
/*   Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <math.h>
# include <stddef.h>
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

# define WIN_MAX_W 1280
# define WIN_MAX_H 720
# define MOVE_S 0.09
# define ROT_S 0.05
# define HITBOX 0.15

typedef struct s_tex
{
	void	*img;
	char	*buf;
	int		bpp;
	int		line;
	int		endian;
	int		w;
	int		h;
}	t_tex;

typedef struct s_imag
{
	void	*walls;
	char	*buf;
	int		bitspp;
	int		endian;
	int		line_len;
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
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
	int				f_set;
	int				c_set;
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
	t_player	player;
	t_map		maps;
	t_window	*win;
}	t_game;

typedef struct s_text
{
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
	double	wallx;
	int		side;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		texx;
	t_tex	*tex;
}	t_ray;

/* ---- game ---- */
void	init_player(t_player *player, t_player_pos *p_pos, char **map);
void	init_ray(t_player *player, t_ray *ray);
void	*render_walls(t_player *player, t_window *win, t_map *map);
void	draw_walls(t_ray *ray, t_window *win, int x);
void	put_wall_pixel(t_render *rend, t_window *w, t_text *tex, t_ray *ray);
void	choose_text(t_ray *ray, t_player *player, t_window *win);
void	init_text(t_text *tex, t_ray *ray, t_render *rend, t_window *w);

/* ---- raycasting ---- */
void	init_sidedist(t_ray *ray, t_player_pos *p_pos);
int		dda(t_ray *ray, char **map);
void	calc_render(t_window *win, t_ray *ray, t_render *rend);
int		is_wall(char **map, double x, double y);

/* ---- parsing ---- */
bool	parsing(char *map_path, t_map *map);
bool	valid_path(char *map_path);
bool	is_readable_file(char *path);
bool	check_textures(t_map *map);
bool	set_textures(t_map *map, char *map_path);
bool	check_color(int *sky_color, int *floor_color);
bool	set_color(t_map *map, char *map_path);
bool	get_map(char *map_path, t_map *map);
bool	add_map_line(t_map *map, char *line);
bool	space_only(char *str);
bool	normalize_map(t_map *map);
bool	validate_map_chars(t_map *game);
bool	is_map_solvable(t_map *game);
int		match_element(char *clean);
bool	handle_tex_line(t_map *map, char *clean);
bool	handle_color_line(t_map *map, char *clean);
bool	valid_component(char *s);
int		count_commas(char *s);
bool	fill_rgb(int *dst, char **rgb);
int		cell_state(char **m, int y, int x);
long	push4(int *sa, long top, int y, int x);
long	stack_cap(char **m);

/* ---- utils ---- */
int		error_msg(char *msg);
size_t	count_tabs(char **tab);
void	free_tabs(char **tab);
void	free_struct(t_map *map);
void	free_map(char **map);
char	**copy_map(char **map);
char	*no_spaces(char *s);
char	*clean_line(char *line);
void	drain_gnl(int fd);

/* ---- window / hooks ---- */
void	*init_window(t_map *map);
void	free_window(t_window *s_win);
void	*free_img(t_imag *img, void *mlx);
void	*init_img(t_imag *img, t_window *win, t_map *map);
int		handle_close(t_game *game);
int		handle_expose(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	exit_win(t_game *win, int code);
#endif
