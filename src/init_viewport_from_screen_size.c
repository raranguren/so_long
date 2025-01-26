/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewport_from_screen_size.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:52 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/19 13:46:29 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_map(t_map *map, int rows, int cols)
{
	int	i;

	map->rows = rows;
	map->cols = cols;
	map->grid = ft_calloc(rows, sizeof(char *));
	if (!map->grid)
		return (-1);
	i = 0;
	while (i < rows)
	{
		map->grid[i] = ft_calloc(cols, sizeof(char));
		if (!map->grid[i])
		{
			while (i)
				free(map->grid[--i]);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_viewport_for_screen_size(t_state *state)
{
	int		x;
	int		y;

	mlx_get_screen_size(state->mlx, &x, &y);
	y = y / SPRITE_SIZE - 1;
	x = y;
	if (y > state->map.rows)
		y = state->map.rows;
	if (x > state->map.cols)
		x = state->map.cols;
	return (init_map(&state->viewport, y, x));
}
