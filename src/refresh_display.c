/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:49 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/16 18:13:31 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	viewport_display_xy(t_state *state, int x, int y)
{
	void	*img;
	int		pos_x;
	int		pos_y;

	img = sprite_to_image(state, state->viewport.grid[y][x]);
	pos_x = SPRITE_SIZE * x;
	pos_y = SPRITE_SIZE * y;
	if (img)
		mlx_put_image_to_window(state->mlx, state->window, img, pos_x, pos_y);
}

static void	moves_display(t_state *state)
{
	if (state->moves > 0)
		ft_printf("\x1bM");
	ft_printf("Movements: %i\n", state->moves);
}

void	refresh_display(t_state *state)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;

	moves_display(state);
	y = 0;
	map_y = state->scroll_y;
	while (y < state->viewport.rows)
	{
		x = 0;
		map_x = state->scroll_x;
		while (x < state->viewport.cols)
		{
			if (state->viewport.grid[y][x] != state->map.grid[map_y][map_x])
			{
				state->viewport.grid[y][x] = state->map.grid[map_y][map_x];
				viewport_display_xy(state, x, y);
			}
			x++;
			map_x++;
		}
		y++;
		map_y++;
	}
}
