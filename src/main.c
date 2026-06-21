#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"

/*static int	validate_map(t_map *game)
{
	if (!validate_map_chars(game))
	{
		return (-1);
	}
	if (is_map_solvable(game) == -1)
		return (-1);
	return (0);
}*/

static bool	check_before_run(t_map *game)
{
	validate_map_chars(game);
	return (true);
}

int main(int argc, char **argv)
{
	t_map	*map;

	ft_bzero(&map, sizeof(t_map));
	map = ft_calloc(1, sizeof(t_map));
	if (argc != 2)
	{
		printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
		return (1);
	}
	parsing(argv[1], map);

	if (check_before_run(map))
	{
		printf("Flood ok !\n");
		printf("Player position X = %f, Y = %f\n", map->player_x, map->player_y);
		is_map_solvable(map);
	}
	return (0);
}
