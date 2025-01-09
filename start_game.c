/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:57:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 00:26:27 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window_hook(t_game_state *state)
{
	mlx_destroy_window(state->mlx, state->window);
	state->window = NULL;
	return (0);
}

int	key_hook(int keycode, t_game_state *state)
{
	if (keycode == XK_Escape)
		return (destroy_window_hook(state));
	return (0);
}

char	*start_game(t_game_state *state)
{
	state->window = mlx_new_window(state->mlx, SPRITE_SIZE * state->map.cols, \
			SPRITE_SIZE * state->map.rows, WINDOW_TITLE);
	if (!state->window)
		return ("Unable to create a window.");
	mlx_key_hook(state->window, key_hook, state);
	mlx_hook(state->window, DestroyNotify, None, destroy_window_hook, state);
	mlx_loop(state->mlx);
	return (0);
}
