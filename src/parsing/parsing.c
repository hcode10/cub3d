#include "parsing.h"
#include <fcntl.h>

bool	valid_path(char *map_path)
{
	(void)map_path;

	return (true);
}

bool	parsing(char *map_path, t_map *map)
{
	int		fd;
	char	*line;
	char	**splited;
	char	**color_split;

	if (!valid_path(map_path))
		return (false);
	fd = open(map_path, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		splited = ft_split(line, ' ');
		if (ft_strncmp("NO", splited[0], 2) == 0)
		{
			map->texture_no = ft_strtrim(splited[1], "\n");
		}
		else if (ft_strncmp("SO", splited[0], 2) == 0)
		{
			map->texture_so = ft_strtrim(splited[1], "\n");
		}
		else if (ft_strncmp("WE", splited[0], 2) == 0)
		{
			map->texture_we = ft_strtrim(splited[1], "\n");
		}
		else if (ft_strncmp("EA", splited[0], 2) == 0)
		{
			map->texture_ea = ft_strtrim(splited[1], "\n");
		}
		else if (ft_strncmp("F", splited[0], 1) == 0)
		{
			color_split = ft_split(splited[1], ',');
			map->floor_color[0] = ft_atoi(color_split[0]);
			map->floor_color[1] = ft_atoi(color_split[1]);
			map->floor_color[2] = ft_atoi(color_split[2]);
		}
		else if (ft_strncmp("C", splited[0], 2) == 0)
		{
			color_split = ft_split(splited[1], ',');
			map->sky_color[0] = ft_atoi(color_split[0]);
			map->sky_color[1] = ft_atoi(color_split[1]);
			map->sky_color[2] = ft_atoi(color_split[2]);
		}
		free(splited);
	}

	printf("texture = \n{%s$ %s$ %s$ %s$};", map->texture_ea, map->texture_no, map->texture_so, map->texture_we);
	printf("texture = \n{%s$ %s$ %s$ %s$};", map->texture_ea, map->texture_no, map->texture_so, map->texture_we);
	
	(void)map;
	return (true);
}
