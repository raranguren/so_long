/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:21:40 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/10 23:15:19 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player_in_map(t_map *map, int *x, int *y)
{
	*y = 1;
	while (*y < map->rows)
	{
		*x = 1;
		while (*x < map->cols)
		{
			if (map->grid[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static int	collectibles_exist(t_map *map)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->rows)
	{
		x = 1;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	moves_display(t_state *state)
{
	ft_printf("Movements: %i\n", state->moves);	
}

void	move_player(t_state *state, int dir_x, int dir_y)
{
	static int	player_x;
	static int	player_y;
	char		destination;

	if (player_x == 0)
		find_player_in_map(&state->map, &player_x, &player_y);
	destination = state->map.grid[player_y + dir_y][player_x + dir_x];
	if (destination == '1')
		return ;
	if (destination == 'E')
	{
		if (collectibles_exist(&state->map))
			return ;
		state->ended = 1;
	}
	state->map.grid[player_y][player_x] = '0';
	map_display(state, player_x, player_y);
	player_x += dir_x;
	player_y += dir_y;
	state->map.grid[player_y][player_x] = 'P';
	map_display(state, player_x, player_y);
	state->moves++;
	moves_display(state);
}
