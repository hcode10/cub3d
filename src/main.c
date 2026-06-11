#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"

int main(int argc, char **argv)
{
	t_map *map;
	if (argc != 2)
	{
		printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	parsing(argv[1], map);
	return (0);
}
