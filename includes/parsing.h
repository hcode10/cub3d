/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:51 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/11 16:11:52 by dcasadio         ###   ########.fr       */
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
	int				floor_color[3];
	int				sky_color[3];
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	t_player_pos	pos;
}	t_map;

bool	parsing(char *map_path, t_map *map);
void 	free_tabs(char **tab);
void	free_struct(t_map *map);

#endif
