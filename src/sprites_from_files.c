/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_from_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:32:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/26 11:37:27 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*sprite_from_file(t_state *state, char *filename)
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

static int	count_tab(void **ptr)
{
	int	count;

	count = 0;
	while (*ptr++)
		count++;
	return (count);
}

int	sprites_from_files(t_state *state)
{
	state->images = ft_calloc(6, sizeof(void *));
	if (!state->images)
		return (-1);
	state->images[IMAGE_INDEX_0] = sprite_from_file(state, SPRITE_FILE_0);
	state->images[IMAGE_INDEX_1] = sprite_from_file(state, SPRITE_FILE_1);
	state->images[IMAGE_INDEX_P] = sprite_from_file(state, SPRITE_FILE_P);
	state->images[IMAGE_INDEX_C] = sprite_from_file(state, SPRITE_FILE_C);
	state->images[IMAGE_INDEX_E] = sprite_from_file(state, SPRITE_FILE_E);
	state->images[5] = NULL;
	if (count_tab(state->images) != 5)
		return (-1);
	return (0);
}
