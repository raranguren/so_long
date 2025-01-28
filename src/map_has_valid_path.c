/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_valid_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:57:41 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 16:26:15 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	grow_p(t_map *map, int x, int y)
{
	if (!map->grid)
		return (0);
	if (map->grid[y][x] == 'P' || map->grid[y][x] == '1')
		return (0);
	if (map->grid[y][x + 1] == 'P' || map->grid[y][x - 1] == 'P' \
			|| map->grid[y + 1][x] == 'P' || map->grid[y - 1][x] == 'P')
	{
		if (map->grid[y][x] == 'E')
			map->grid[y][x] = '1';
		else
			map->grid[y][x] = 'P';
		return (1);
	}
	return (0);
}

static void	map_copy(t_map *dest, t_map *src)
{
	int		row;
	char	*line;

	*dest = *src;
	dest->grid = malloc(src->rows * sizeof(char *));
	if (dest->grid)
	{
		row = 0;
		while (row < dest->rows)
		{
			line = ft_strdup(src->grid[row]);
			if (!line)
			{
				while (row)
					free(dest->grid[--row]);
				free(dest->grid);
				dest->grid = NULL;
				return ;
			}
			dest->grid[row++] = line;
		}
	}
}

static void	map_clear(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
		free(map->grid[y++]);
	free(map->grid);
}

static int	is_solved(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'E' || map->grid[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
 * Verifies that the 'P' player can reach all collectibles 'P' and the exit 'E'.
 * Note that the map is copied before the check. The algorithm sets all
 * reachable places with a 'P' and then checks that the exit and collectibles
 * are no longer there.
 * It is assumed that the map is closed with '1' borders.
 * Returns boolean (1 for valid, 0 for invalid)
 */
int	map_has_valid_path(t_map *map_original)
{
	t_map	map;
	int		count;
	int		x;
	int		y;

	map_copy(&map, map_original);
	count = 1;
	while (count)
	{
		count = 0;
		y = 1;
		while (y < map.rows)
		{
			x = 1;
			while (x < map.cols)
			{
				count += grow_p(&map, x, y);
				x++;
			}
			y++;
		}
	}
	count = is_solved(&map);
	map_clear(&map);
	return (count);
}
