/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:57:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/16 17:43:13 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	destroy_window_hook(t_state *state)
{
	mlx_destroy_window(state->mlx, state->window);
	state->window = NULL;
	mlx_loop_end(state->mlx);
	return (0);
}

static int	key_hook(int keycode, t_state *state)
{
	if (keycode == XK_Escape)
		return (destroy_window_hook(state));
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(state, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(state, 0, 1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(state, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(state, 1, 0);
	if (state->ended)
		destroy_window_hook(state);
	return (0);
}

static int	expose_hook(t_state *state)
{
	move_player(state, 0, 0);
	return (0);
}

char	*start_game(t_state *state)
{
	if (sprites_from_files(state) < 0)
		return ("Error loading sprites from files.");
	if (init_viewport_for_screen_size(state))
		return ("Not enough memory for scroll system.");
	state->window = mlx_new_window(state->mlx, \
			SPRITE_SIZE * state->viewport.cols, \
			SPRITE_SIZE * state->viewport.rows, WINDOW_TITLE);
	if (!state->window)
		return ("Unable to create a window.");
	mlx_expose_hook(state->window, expose_hook, state);
	mlx_key_hook(state->window, key_hook, state);
	mlx_hook(state->window, DestroyNotify, None, destroy_window_hook, state);
	mlx_loop(state->mlx);
	return (0);
}
