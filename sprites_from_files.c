/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_from_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:32:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 14:06:48 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*sprite_from_file(t_game_state *state, char *filename)
{
	int		height;
	int		width;
	void	*img;

	height = SPRITE_SIZE;
	width = SPRITE_SIZE;
	img = mlx_xpm_file_to_image(state->mlx, filename, &width, &height);
	if (!img)
		return (NULL);
	if (width == SPRITE_SIZE && height == SPRITE_SIZE)
		return (img);
	mlx_destroy_image(state->mlx, img);
	return (NULL);
}

int	sprites_from_files(t_game_state *state)
{
	state->sprites.empty = sprite_from_file(state, SPRITE_FILE_0);
	state->sprites.wall = sprite_from_file(state, SPRITE_FILE_1);
	state->sprites.player = sprite_from_file(state, SPRITE_FILE_P);
	state->sprites.collectible = sprite_from_file(state, SPRITE_FILE_C);
	state->sprites.exit = sprite_from_file(state, SPRITE_FILE_E);
	if (state->sprites.empty && state->sprites.wall && state->sprites.player \
			&& state->sprites.collectible && state->sprites.exit)
		return (0);
	return (-1);
}
