/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_display_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:49 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 15:53:03 by rarangur         ###   ########.fr       */
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
	static char	str[] = "Movements:             ";
	static int	nbr_visible = -1;
	char		*nbr;

	if (nbr_visible != state->moves)
	{
		nbr_visible = state->moves;
		nbr = ft_itoa(nbr_visible);
		if (!nbr)
			return ;
		ft_strlcpy(str + 11, nbr, 13);
		free(nbr);
	}
	mlx_string_put(state->mlx, state->window, 10, 28, 0xFFFFFF, str);
}

void	clear_on_animation(t_state *state)
{
	static void	*already_animated_image;
	int			y;

	if (already_animated_image == state->images[ANIMATIONS_FIRST_INDEX])
		return ;
	y = 0;
	while (y < state->viewport.rows)
	{
		ft_bzero(state->viewport.grid[y], state->viewport.cols);
		y++;
	}
	mlx_clear_window(state->mlx, state->window);	
}

void	refresh_display(t_state *state)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;

	clear_on_animation(state);
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
	moves_display(state);
}
