/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:57:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 15:45:09 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window_hook(t_game_state *state)
{
	mlx_destroy_window(state->mlx, state->window);
	state->window = NULL;
	mlx_loop_end(state->mlx);
	return (0);
}

int	key_hook(int keycode, t_game_state *state)
{
	if (keycode == XK_Escape)
		return (destroy_window_hook(state));
	else if (keycode == XK_w)
		move_player(state, 0, -1);
	else if (keycode == XK_s)
		move_player(state, 0, 1);
	else if (keycode == XK_a)
		move_player(state, -1, 0);
	else if (keycode == XK_d)
		move_player(state, 1, 0);
	if (state->ended)
		destroy_window_hook(state);
	return (0);
}

int	expose_hook(t_game_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->map.rows)
	{
		x = 0;
		while (x < state->map.cols)
		{
			map_display(state, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

char	*start_game(t_game_state *state)
{
	if (sprites_from_files(state) < 0)
		return ("Error loading sprites from files.");
	state->window = mlx_new_window(state->mlx, SPRITE_SIZE * state->map.cols, \
			SPRITE_SIZE * state->map.rows, WINDOW_TITLE);
	if (!state->window)
		return ("Unable to create a window.");
	mlx_expose_hook(state->window, expose_hook, state);
	mlx_key_hook(state->window, key_hook, state);
	mlx_hook(state->window, DestroyNotify, None, destroy_window_hook, state);
	mlx_loop(state->mlx);
	return (0);
}
