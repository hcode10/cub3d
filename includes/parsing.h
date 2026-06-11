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

#endif
