/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:50 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 22:19:24 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Counts the special characters in a map.
 * Returns -1 if it finds invalid characters or lines have different sizes.
 */
static int	count_elements(t_map *map, int *e, int *p, int *c)
{
	int	x;
	int	y;

	*e = 0;
	*p = 0;
	*c = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'P')
				(*p)++;
			else if (map->grid[y][x] == 'E')
				(*e)++;
			else if (map->grid[y][x] == 'C')
				(*c)++;
			else if (map->grid[y][x] != '1' && map->grid[y][x] != '0')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
 * Checks that the map is closed/surrounded by '1'.
 * Returns boolean (1 for closed map, 0 for open map)
 */
static int	has_border(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = map->rows - 1;
	while (x < map->cols)
	{
		if (map->grid[0][x] != '1' || map->grid[y][x] != '1')
			return (0);
		x++;
	}
	x = map->cols - 1;
	y = 0;
	while (y < map->rows)
	{
		if (map->grid[y][0] != '1' || map->grid[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

/*
 * Returns a string explaining the problem found in a map.
 * NULL if the map is valid.
 */
char	*map_validate(t_map *map)
{
	int	count_exits;
	int	count_starts;
	int	count_collectibles;

	if (map->rows < 3 || map->cols < 3)
		return ("The map is too small to contain all elements.");
	if (count_elements(map, &count_exits, &count_starts, &count_collectibles))
		return ("The map must be a rectangle made with characters '01EC'.");
	if (count_exits != 1)
		return ("The map must have 1 exit.");
	if (count_starts != 1)
		return ("The map must have 1 starting position.");
	if (count_collectibles < 1)
		return ("The map must have at least 1 collectible.");
	if (!has_border(map))
		return ("The map must be closed/surrounded by walls.");
	if (!map_has_valid_path(map))
		return ("The map must have a valid path.");
	return (NULL);
}
