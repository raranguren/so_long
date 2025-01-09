/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:49 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 20:27:27 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_display(t_state *state, int x, int y)
{
	void	*img;
	int		pos_x;
	int		pos_y;

	pos_x = SPRITE_SIZE * x;
	pos_y = SPRITE_SIZE * y;
	img = sprite_to_image(state, '0');
	if (img)
		mlx_put_image_to_window(state->mlx, state->window, img, pos_x, pos_y);
	img = sprite_to_image(state, state->map.grid[y][x]);
	if (img)
		mlx_put_image_to_window(state->mlx, state->window, img, pos_x, pos_y);
}
