/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:11:45 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/12 15:30:41 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	if (argc != 2)
		return (error_msg("Usage: ./cub3D <map.cub>"));
	if (!parsing(argv[1], &map))
		return (free_struct(&map), 1);
	dbg_step("validate_map_chars + is_map_solvable");
	if (!validate_map_chars(&map) || !is_map_solvable(&map))
		return (free_struct(&map), 1);
	free_struct(&map);
	return (0);
}
