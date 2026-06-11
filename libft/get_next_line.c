/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coressor <coressor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:11:11 by coressor          #+#    #+#             */
/*   Updated: 2026/02/18 14:58:27 by coressor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_n_save(int fd, char *str)
{
	char	*buff;
	int		read_ret;
	char	*s;

	s = NULL;
	buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buff)
		return (free(str), NULL);
	read_ret = 1;
	while (!ft_strchr(str, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(str), free(buff), NULL);
		buff[read_ret] = 0;
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	free(s);
	free(buff);
	return (str);
}

static char	*extract_line(char *str)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(len * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*update_str(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (!str[j])
		return (free(str), NULL);
	new_str = malloc((ft_strlen(str) - j) * sizeof(char));
	if (!new_str)
		return (free(str), NULL);
	j++;
	while (str[j])
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_n_save(fd, str);
	if (!str)
		return (NULL);
	line = extract_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = update_str(str);
	return (line);
}
