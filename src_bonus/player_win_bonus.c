/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:43 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 16:36:53 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_win(t_state *state, int exit_x, int exit_y)
{
	int	y;

	y = 0;
	while (y < state->map.rows)
	{
		ft_bzero(state->map.grid[y], state->map.cols);
		y++;
	}
	if (exit_y > state->map.rows - 3)
		exit_y = state->map.rows - 3;
	if (exit_x > state->map.cols - 3)
		exit_x = state->map.cols - 3;
	state->map.grid[exit_y][exit_x] = 'W';
	state->ended = 1;
	mlx_clear_window(state->mlx, state->window);
}
