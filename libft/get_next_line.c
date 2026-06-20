<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:06:59 by dcasadio          #+#    #+#             */
/*   Updated: 2026/06/21 12:19:40 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static char	*get_line(char *storage)
{
	int		i;
	char	*line;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(i + (storage[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_and_join(char *storage, int fd, int *eof, int *found_nl)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage), NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), free(storage), NULL);
	if (bytes_read == 0)
		return (*eof = 1, free(buffer), storage);
	buffer[bytes_read] = '\0';
	if (ft_strchr(buffer, '\n'))
		*found_nl = 1;
	temp = ft_strjoin(storage, buffer);
	free(buffer);
	if (!temp)
		return (free(storage), NULL);
	free(storage);
	return (temp);
}

static char	*read_more(char *storage, int fd)
{
	char	*temp;
	int		eof_reached;
	int		found_nl;

	eof_reached = 0;
	found_nl = 0;
	if (!storage)
	{
		storage = malloc(1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	while (!eof_reached && !found_nl)
	{
		temp = read_and_join(storage, fd, &eof_reached, &found_nl);
		if (!temp)
			return (NULL);
		storage = temp;
		if (storage[0] == '\0')
			return (storage);
	}
	return (storage);
}

static char	*update_storage(char *storage)
{
	size_t	i;
	size_t	j;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i] || !storage[i + 1])
		return (free(storage), NULL);
	i++;
	new_storage = malloc(ft_strlen(storage + i) + 1);
	if (!new_storage)
		return (free(storage), NULL);
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_more(storage, fd);
	if (!storage)
		return (NULL);
	if (!storage[0])
		return (free(storage), storage = NULL, NULL);
	line = get_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = update_storage(storage);
	return (line);
}

/*
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	// Ouvrir le fichier 1.txt
	fd = open("1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur: impossible d'ouvrir le fichier 1.txt\n");
		return (1);
	}

	printf("=== Test de get_next_line avec 1.txt ===\n\n");
	
	line_count = 1;
	// Lire ligne par ligne jusqu'à la fin du fichier
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Ligne %d: %s", line_count, line);
		free(line);
		if (line_count > 10)
			break;
		line_count++;
	}

	printf("\n=== Fin du fichier (Total: %d lignes) ===\n", line_count - 1);
	
	// Fermer le fichier
	close(fd);
	
	return (0);
}*/
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:11:11 by coressor          #+#    #+#             */
/*   Updated: 2026/06/12 12:29:30 by dcasadio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "get_next_line.h"

static char	*get_line(char *storage)
{
	int		i;
	char	*line;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(i + (storage[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_and_join(char *storage, int fd, int *eof, int *found_nl)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage), NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), free(storage), NULL);
	if (bytes_read == 0)
		return (*eof = 1, free(buffer), storage);
	buffer[bytes_read] = '\0';
	if (ft_strchr(buffer, '\n'))
		*found_nl = 1;
	temp = ft_strjoin(storage, buffer);
	free(buffer);
	if (!temp)
		return (free(storage), NULL);
	free(storage);
	return (temp);
}

static char	*read_more(char *storage, int fd)
{
	char	*temp;
	int		eof_reached;
	int		found_nl;

	eof_reached = 0;
	found_nl = 0;
	if (!storage)
	{
		storage = malloc(1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	while (!eof_reached && !found_nl)
	{
		temp = read_and_join(storage, fd, &eof_reached, &found_nl);
		if (!temp)
			return (NULL);
		storage = temp;
		if (storage[0] == '\0')
			return (storage);
	}
	return (storage);
}

static char	*update_storage(char *storage)
{
	size_t	i;
	size_t	j;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i] || !storage[i + 1])
		return (free(storage), NULL);
	i++;
	new_storage = malloc(ft_strlen(storage + i) + 1);
	if (!new_storage)
		return (free(storage), NULL);
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_more(storage, fd);
	if (!storage)
		return (NULL);
	if (!storage[0])
		return (free(storage), storage = NULL, NULL);
	line = get_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = update_storage(storage);
	return (line);
}
>>>>>>> ddcb1a0 (Putain de git de merde)
