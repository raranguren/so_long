/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_patrols_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:56:30 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/26 16:42:05 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
 * Places the code for a patrol in an empty place close to the center of
 * a square. If no spot is found, does nothing.
 *
 *  (min_x, min_y) --> +-------+
 *                     |       |
 *                     |   + <-- (min_x + PATROL_RADIUS, min_y + PATROL_RADIUS
 *                     |       |
 *                     +-------+
 */
static void	place_patrol_in_square(t_map *map, int min_x, int min_y)
{
	int	area_size;
	int	x;
	int	y;

	area_size = 1;
	while (area_size < PATROL_RADIUS)
	{
		y = min_y + PATROL_RADIUS - area_size;
		while (y < map->rows && y < min_y + PATROL_RADIUS + area_size)
		{
			x = min_x + PATROL_RADIUS - area_size;
			while (x < map->cols && x < min_x + PATROL_RADIUS + area_size)
			{
				if (map->grid[y][x] == '0')
				{
					map->grid[y][x] = '6';
					return ;
				}
				x++;
			}
			y++;
		}
		area_size++;
	}
}

static int	is_player_in_square(t_map *map, int min_x, int min_y)
{
	int	x;
	int	y;

	y = min_y;
	while (y < map->rows && y < min_y + PATROL_RADIUS * 2)
	{
		x = min_x;
		while (x < map->cols && x < min_x + PATROL_RADIUS * 2)
		{
			if (map->grid[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	init_patrols(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (!is_player_in_square(map, x, y))
				place_patrol_in_square(map, x, y);
			x += PATROL_RADIUS * 2;
		}
		y += PATROL_RADIUS * 2;
	}
}
