/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:53:25 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/21 16:19:37 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../includes/parsing.h"
#include <fcntl.h>

/*static int	check_line_width(t_map *game, char *line, size_t line_size)
{
	if (line_size > 0 && line[line_size - 1] == '\n')
		line_size--;
	if (game->width == 0)
		game->width = line_size;
	if (game->width != line_size && line_size != 0)
		return (-1);
	return (0);
}*/

/*static void	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}*/

/*static int	open_and_alloc_map(t_map *game)
{
	int	i;
	int	height;

	height = map_count_line();
	if (height < 0)
		return (-1);
	game->map = malloc(sizeof(char *) * (height + 1));
	if (!game->map)
		return (-1);
	i = 0;
	while (i <= height)
		game->map[i++] = NULL;
	return (0);
}*/

int	read_map(t_map *game)
{
	if (validate_map_chars(game) != 0)
	{
		if (game->p_pos.x == 0 || game->p_pos.y == 0)
			ft_putstr_fd("Player invalide !\n", 0);
		else
			ft_putstr_fd("Caracteres invalides !\n", 0);
		free_map(game->map);
		return (-1);
	}
	return (0);
}
