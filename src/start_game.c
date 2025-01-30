/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:57:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/30 05:17:21 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_state *state)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(state->mlx));
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(state, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(state, 0, 1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(state, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(state, 1, 0);
	if (state->ended)
		mlx_loop_end(state->mlx);
	return (0);
}

static int	expose_hook(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->viewport.rows)
	{
		x = 0;
		while (x < state->viewport.cols)
		{
			state->viewport.grid[y][x] = 0;
			x++;
		}
		y++;
	}
	move_player(state, 0, 0);
	return (0);
}

char	*start_game(t_state *state)
{
	if (sprites_from_files(state) < 0)
		return ("Error loading sprites from files.");
	if (init_viewport(state))
		return ("Not enough memory for scroll system.");
	state->window = mlx_new_window(state->mlx, \
			SPRITE_SIZE * state->viewport.cols, \
			SPRITE_SIZE * state->viewport.rows, WINDOW_TITLE);
	if (!state->window)
		return ("Unable to create a window.");
	mlx_expose_hook(state->window, expose_hook, state);
	mlx_key_hook(state->window, key_hook, state);
	mlx_hook(state->window, DestroyNotify, None, mlx_loop_end, state->mlx);
	mlx_loop(state->mlx);
	return (0);
}
