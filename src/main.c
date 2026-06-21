#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	if (argc != 2)
		return (error_msg("Usage: ./cub3D <map.cub>"));
	if (!parsing(argv[1], &map))
		return (free_struct(&map), 1);
	if (!validate_map_chars(&map) || !is_map_solvable(&map))
		return (free_struct(&map), 1);
	free_struct(&map);
	return (0);
}
