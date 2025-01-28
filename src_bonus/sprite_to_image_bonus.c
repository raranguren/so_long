/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:23:26 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:42 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*patrol_to_image(t_state *state, char code)
{
	if (code == '6')
		return (state->images[IMAGE_INDEX_6_0]);
	if (code == '7')
		return (state->images[IMAGE_INDEX_7_0]);
	if (code == '8')
		return (state->images[IMAGE_INDEX_8_0]);
	if (code == '9')
		return (state->images[IMAGE_INDEX_9_0]);
	return (NULL);
}

void	*wall_to_image(t_state *state, char code)
{
	if (code == '1')
		return (state->images[IMAGE_INDEX_1]);
	if (code == '2')
		return (state->images[IMAGE_INDEX_2_0]);
	if (code == '3')
		return (state->images[IMAGE_INDEX_3_0]);
	if (code == '4')
		return (state->images[IMAGE_INDEX_4_0]);
	return (NULL);
}

void	*sprite_to_image(t_state *state, char code)
{
	if (code == '0')
		return (state->images[IMAGE_INDEX_0]);
	if (code == 'P')
		return (state->images[IMAGE_INDEX_P_0]);
	if (code == 'C')
		return (state->images[IMAGE_INDEX_C_0]);
	if (code == 'E')
		return (state->images[IMAGE_INDEX_E_0]);
	if (code == 'D')
		return (state->images[IMAGE_INDEX_D_0]);
	if (code >= '6' && code <= '9')
		return (patrol_to_image(state, code));
	if (code >= '1' && code <= '4')
		return (wall_to_image(state, code));
	if (code == 'W')
		return (state->images[IMAGE_INDEX_W_0]);
	return (NULL);
}
