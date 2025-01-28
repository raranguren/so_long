/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:21:40 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 15:57:03 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	find_player_in_map(t_map *map, int *x, int *y)
{
	if (*x)
		return ;
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

static void	center_player(t_state *state, int player_x, int player_y)
{
	int	padding;
	int	dist;

	padding = state->viewport.cols * SCROLL_TRIGGER_PERCENT / 100;
	dist = player_x - state->scroll_x;
	if (dist < padding)
		state->scroll_x -= padding - dist;
	dist = state->viewport.cols - dist - 1;
	if (dist < padding)
		state->scroll_x += padding - dist;
	if (state->scroll_x < 0)
		state->scroll_x = 0;
	else if (state->scroll_x + state->viewport.cols > state->map.cols)
		state->scroll_x = state->map.cols - state->viewport.cols;
	padding = state->viewport.rows * SCROLL_TRIGGER_PERCENT / 100;
	dist = player_y - state->scroll_y;
	if (dist < padding)
		state->scroll_y -= padding - dist;
	dist = state->viewport.rows - dist - 1;
	if (dist < padding)
		state->scroll_y += padding - dist;
	if (state->scroll_y < 0)
		state->scroll_y = 0;
	else if (state->scroll_y + state->viewport.rows > state->map.rows)
		state->scroll_y = state->map.rows - state->viewport.rows;
}

void	move_patrols_and_die(t_state *state, int x, int y)
{
	char	**grid;

	grid = state->map.grid;
	move_patrols(&state->map);
	if (\
			(grid[y + 1][x] >= '6' && state->map.grid[y + 1][x] <= '9') || \
			(grid[y - 1][x] >= '6' && state->map.grid[y - 1][x] <= '9') || \
			(grid[y][x + 1] >= '6' && state->map.grid[y][x + 1] <= '9') || \
			(grid[y][x - 1] >= '6' && state->map.grid[y][x - 1] <= '9'))
	{
		grid[y][x] = 'D';
		state->ended = 1;
	}
}

void	move_player(t_state *state, int dir_x, int dir_y)
{
	static int	player_x;
	static int	player_y;
	char		destination;

	if (state->ended)
		return ;
	find_player_in_map(&state->map, &player_x, &player_y);
	destination = state->map.grid[player_y + dir_y][player_x + dir_x];
	if (destination == 'E' && !collectibles_exist(&state->map))
		player_win(state, player_x + dir_x, player_y + dir_y);
	if (!(destination >= '1' && destination <= '4') && destination != 'E')
	{
		state->map.grid[player_y][player_x] = '0';
		player_x += dir_x;
		player_y += dir_y;
		state->map.grid[player_y][player_x] = 'P';
	}
	state->moves += (dir_x || dir_y);
	move_patrols_and_die(state, player_x, player_y);
	center_player(state, player_x, player_y);
	refresh_display(state);
}
