#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"

int main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	if (argc != 2)
	{
		printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
		return (1);
	}
	if (!parsing(argv[1], &map))
	{
		printf("Erreur de parsing !\n");
		free_struct(&map);
		return (1);
	}
	printf("Parsing OK");
	free_struct(&map);
	return (0);
}
