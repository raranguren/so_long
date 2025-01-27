/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:57:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/27 19:46:32 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	return (0);
}

static int	expose_hook(t_state *state)
{
	int	y;

	y = 0;
	while (y < state->viewport.rows)
	{
		ft_bzero(state->viewport.grid[y], state->viewport.cols);
		y++;
	}
	return (0);
}

static int	loop_hook(t_state *state)
{
	static int	loops;
	int			i;
	void		*temp;

	if (++loops < LOOPS_PER_ANIMATION)
		return (0);
	loops = 0;
	i = ANIMATIONS_INDEX;
	while (i < COUNT_IMAGES)
	{
		temp = state->images[i];
		state->images[i] = state->images[i + 1];
		state->images[i + 1] = state->images[i + 2];
		state->images[i + 2] = temp;
		i += 3;
	}
	if (state->ended >= 1)
	{
		state->ended++;
		if (state->ended >= ANIMATIONS_AFTER_ENDED)
			return (destroy_window_hook(state));
	}
	refresh_display(state);
	return (0);
}

char	*start_game(t_state *state)
{
	decorate_map(&state->map);
	init_patrols(&state->map);
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
	mlx_hook(state->window, DestroyNotify, None, destroy_window_hook, state);
	mlx_loop_hook(state->mlx, loop_hook, state);
	mlx_loop(state->mlx);
	return (0);
}
