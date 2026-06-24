/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:51 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/21 14:37:01 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

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
void	dbg_step(char *msg);
void	dbg_textures(t_map *map);
void	dbg_colors(t_map *map);
void	dbg_map(t_map *map);
void	dbg_flood(t_flood *flood);
void	dbg_val(char *tag, char *val);
void	dbg_fail(char *where, char *why);
char	*no_spaces(char *s);

#endif
