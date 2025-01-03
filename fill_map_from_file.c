/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:45 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/03 17:31:47 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_map_from_file(t_ber_map *map, char *filename)
{
	int			fd;
	char		*line;

	ft_bzero(map, sizeof(*map));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	   return (-1);
	while ((line = get_next_line(fd)))
	{
		if (map->cols == 0)
			map->cols = ft_strlen(line) - 1;
		ft_memcpy(map->grid[map->rows], line, map->cols);
		map->rows++;
		free(line);
	}
	close(fd);
	return (0);
}
