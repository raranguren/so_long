/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_from_files_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:32:21 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 15:07:23 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	return (img);
}

static int	count_tab(void **ptr)
{
	int	count;

	count = 0;
	while (*ptr++)
		count++;
	return (count);
}

static void	load_game_images(t_state *state)
{
	state->images[IMAGE_INDEX_0] = sprite_from_file(state, SPRITE_FILE_0);
	state->images[IMAGE_INDEX_1] = sprite_from_file(state, SPRITE_FILE_1);
	state->images[IMAGE_INDEX_P] = sprite_from_file(state, SPRITE_FILE_P);
	state->images[IMAGE_INDEX_C] = sprite_from_file(state, SPRITE_FILE_C);
	state->images[IMAGE_INDEX_E] = sprite_from_file(state, SPRITE_FILE_E);
	state->images[IMAGE_INDEX_P_0] = sprite_from_file(state, SPRITE_FILE_P_0);
	state->images[IMAGE_INDEX_P_1] = sprite_from_file(state, SPRITE_FILE_P_1);
	state->images[IMAGE_INDEX_P_2] = sprite_from_file(state, SPRITE_FILE_P_2);
	state->images[IMAGE_INDEX_C_0] = sprite_from_file(state, SPRITE_FILE_C_0);
	state->images[IMAGE_INDEX_C_1] = sprite_from_file(state, SPRITE_FILE_C_1);
	state->images[IMAGE_INDEX_C_2] = sprite_from_file(state, SPRITE_FILE_C_2);
	state->images[IMAGE_INDEX_E_0] = sprite_from_file(state, SPRITE_FILE_E_0);
	state->images[IMAGE_INDEX_E_1] = sprite_from_file(state, SPRITE_FILE_E_1);
	state->images[IMAGE_INDEX_E_2] = sprite_from_file(state, SPRITE_FILE_E_2);
	state->images[IMAGE_INDEX_D_0] = sprite_from_file(state, SPRITE_FILE_D_0);
	state->images[IMAGE_INDEX_D_1] = sprite_from_file(state, SPRITE_FILE_D_1);
	state->images[IMAGE_INDEX_D_2] = sprite_from_file(state, SPRITE_FILE_D_2);
	state->images[IMAGE_INDEX_W_0] = sprite_from_file(state, SPRITE_FILE_W_0);
	state->images[IMAGE_INDEX_W_1] = sprite_from_file(state, SPRITE_FILE_W_1);
	state->images[IMAGE_INDEX_W_2] = sprite_from_file(state, SPRITE_FILE_W_2);
}

static void	load_cosmetic_images(t_state *state)
{
	state->images[IMAGE_INDEX_2_0] = sprite_from_file(state, SPRITE_FILE_2_0);
	state->images[IMAGE_INDEX_2_1] = sprite_from_file(state, SPRITE_FILE_2_1);
	state->images[IMAGE_INDEX_2_2] = sprite_from_file(state, SPRITE_FILE_2_2);
	state->images[IMAGE_INDEX_3_0] = sprite_from_file(state, SPRITE_FILE_3_0);
	state->images[IMAGE_INDEX_3_1] = sprite_from_file(state, SPRITE_FILE_3_1);
	state->images[IMAGE_INDEX_3_2] = sprite_from_file(state, SPRITE_FILE_3_2);
	state->images[IMAGE_INDEX_4_0] = sprite_from_file(state, SPRITE_FILE_4_0);
	state->images[IMAGE_INDEX_4_1] = sprite_from_file(state, SPRITE_FILE_4_1);
	state->images[IMAGE_INDEX_4_2] = sprite_from_file(state, SPRITE_FILE_4_2);
	state->images[IMAGE_INDEX_6_0] = sprite_from_file(state, SPRITE_FILE_6_0);
	state->images[IMAGE_INDEX_6_1] = sprite_from_file(state, SPRITE_FILE_6_1);
	state->images[IMAGE_INDEX_6_2] = sprite_from_file(state, SPRITE_FILE_6_2);
	state->images[IMAGE_INDEX_7_0] = sprite_from_file(state, SPRITE_FILE_7_0);
	state->images[IMAGE_INDEX_7_1] = sprite_from_file(state, SPRITE_FILE_7_1);
	state->images[IMAGE_INDEX_7_2] = sprite_from_file(state, SPRITE_FILE_7_2);
	state->images[IMAGE_INDEX_8_0] = sprite_from_file(state, SPRITE_FILE_8_0);
	state->images[IMAGE_INDEX_8_1] = sprite_from_file(state, SPRITE_FILE_8_1);
	state->images[IMAGE_INDEX_8_2] = sprite_from_file(state, SPRITE_FILE_8_2);
	state->images[IMAGE_INDEX_9_0] = sprite_from_file(state, SPRITE_FILE_9_0);
	state->images[IMAGE_INDEX_9_1] = sprite_from_file(state, SPRITE_FILE_9_1);
	state->images[IMAGE_INDEX_9_2] = sprite_from_file(state, SPRITE_FILE_9_2);
}

int	sprites_from_files(t_state *state)
{
	int	i;

	state->images = ft_calloc(COUNT_IMAGES + 1, sizeof(void *));
	if (!state->images)
		return (-1);
	load_game_images(state);
	load_cosmetic_images(state);
	state->images[COUNT_IMAGES] = NULL;
	if (count_tab(state->images) < COUNT_IMAGES)
	{
		i = 0;
		while (i < COUNT_IMAGES)
		{
			if (state->images[i])
				mlx_destroy_image(state->mlx, state->images[i]);
			i++;
		}
		free(state->images);
		state->images = NULL;
		return (-1);
	}
	return (0);
}
