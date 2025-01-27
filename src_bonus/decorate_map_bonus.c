/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:47:17 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/27 21:37:29 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	decorate_wall(char **grid, int x, int y)
{
	if (grid[y + 1][x] != '1' || grid[y - 1][x] == '1')
		return ;
	if (grid[y - 1][x] == '4' || grid[y - 1][x] == '3')
	{
		if (grid[y][x - 1] == '3' && grid[y][x + 1] == '3')
			return ;
		grid[y][x] = '3';
		return ;
	}
	if (grid[y][x - 1] != '1' || grid[y][x + 1] != '1')
		grid[y][x] = '4';
}

/*
 * Decorates walls.
 * First replaces all the first row with '2': waves
 * Then replaces walls with seaweed when it makes sense.
 */
void	decorate_map(t_map *map)
{
	int		y;
	int		x;

	ft_memset(map->grid[0], '2', map->cols);
	y = 1;
	while (y < map->rows - 1)
	{
		x = 1;
		while (x < map->cols - 1)
		{
			if (map->grid[y][x] == '1')
				decorate_wall(map->grid, x, y);
			x++;
		}
		y++;
	}
}
