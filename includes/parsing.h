/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:51 by dcasadio          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/21 14:37:01 by dcasadio         ###   ########.fr       */
=======
/*   Updated: 2026/06/11 16:11:52 by dcasadio         ###   ########.fr       */
>>>>>>> b80446b (Ajout des fonction set et check)
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSE
# define CUB_PARSE

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

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
	t_player_pos	pos;
	size_t			width;
	size_t			height;
}	t_map;

typedef struct s_flood
{
	size_t	player_count;
}	t_flood;

bool	parsing(char *map_path, t_map *map);
void 	free_tabs(char **tab);
void	free_struct(t_map *map);
char	**copy_map(char **map);
void	aff_map(char **map);
void	free_map(char **map);
int		validate_map_chars(t_map *game);
int		validate_map_walls(t_map *game);
int		read_map(t_map *game);
int		is_map_solvable(t_map *game);
void	set_heigth(t_map *game, int height);
int		map_count_line();

#endif
