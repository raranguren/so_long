/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:45 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/10 23:21:18 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		len;

	ft_bzero(map, sizeof(t_map));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		free(line);
		if (len > map->cols)
			map->cols = len;
		map->rows++;
	}
	close(fd);
	map->grid = malloc(map->rows * sizeof(char *));
	if (!map->grid)
		return (-1);
	return (0);
}

int	fill_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		row;

	row = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (row < map->rows)
	{
		line = get_next_line(fd);
		if (line)
			map->grid[row++] = line;
	}
	close(fd);
	if (row < map->rows)
	{
		while (row)
			free(map->grid[--row]);
		free(map->grid);
		map->grid = NULL;
		return (-1);
	}
	return (0);
}

int	map_from_file(t_map *map, char *filename)
{
	if (init_map(map, filename))
		return (-1);
	if (fill_map(map, filename))
		return (-1);
	return (0);
}
