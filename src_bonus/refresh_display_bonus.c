/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_display_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:49 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/26 19:25:13 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	viewport_display_xy(t_state *state, int x, int y, char sprite)
{
	void	*img;
	int		pos_x;
	int		pos_y;

	if (state->viewport.grid[y][x] == sprite)
		return ;
	img = sprite_to_image(state, sprite);
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

void	clear_on_animation(t_state *state)
{
	static void	*first_animated_image;
	int			y;

	if (first_animated_image == state->images[ANIMATIONS_INDEX])
		return ;
	y = 0;
	while (y < state->viewport.rows)
	{
		ft_bzero(state->viewport.grid[y], state->viewport.cols);
		y++;
	}
}

void	refresh_display(t_state *state)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;

	clear_on_animation(state);
	moves_display(state);
	y = 0;
	map_y = state->scroll_y;
	while (y < state->viewport.rows)
	{
		x = 0;
		map_x = state->scroll_x;
		while (x < state->viewport.cols)
		{
			viewport_display_xy(state, x, y, state->map.grid[map_y][map_x]);
			x++;
			map_x++;
		}
		y++;
		map_y++;
	}
}
