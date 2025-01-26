/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_patrols_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:28:22 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/26 18:33:01 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
 * Changes the grid depending on the original code of the patrol.
 * If the next spot is not empty, it will rotate the patrol.
 *
 *        '6' north
 *        /\
 *  '9' <    > '7' east
 *  west  \/
 *        '8' south
 */
void	move_patrol(char **grid, int x, int y, char code)
{
	int	xv;
	int	yv;

	xv = 0;
	yv = 0;
	if (code == '6')
		yv = -1;
	else if (code == '7')
		xv = 1;
	else if (code == '8')
		yv = 1;
	else if (code == '9')
		xv = -1;
	if (grid[y + yv][x + xv] == '0')
	{
		x += xv;
		y += yv;
	}
	else
	{
		code++;
		if (code > '9')
			code = '6';
	}
	grid[y][x] = code;
}

void	move_patrols(t_map *map)
{
	int		x;
	int		y;
	char	code;

	y = 1;
	while (y < map->rows)
	{
		x = 1;
		while (x < map->cols)
		{
			code = map->grid[y][x];
			if (code >= '6' && code <= '9')
			{
				map->grid[y][x] = '.';
				move_patrols(map);
				map->grid[y][x] = '0';
				move_patrol(map->grid, x, y, code);
				return ;
			}
			x++;
		}
		y++;
	}
}
