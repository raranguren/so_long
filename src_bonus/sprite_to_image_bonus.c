/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:23:26 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/26 17:27:12 by rarangur         ###   ########.fr       */
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

void	*sprite_to_image(t_state *state, char code)
{
	if (code == '0')
		return (state->images[IMAGE_INDEX_0]);
	if (code == '1')
		return (state->images[IMAGE_INDEX_1]);
	if (code == 'P')
		return (state->images[IMAGE_INDEX_P]);
	if (code == 'C')
		return (state->images[IMAGE_INDEX_C]);
	if (code == 'E')
		return (state->images[IMAGE_INDEX_E]);
	if (code == 'D')
		return (state->images[IMAGE_INDEX_D_0]);
	if (code >= '6' && code <= '9')
		return (patrol_to_image(state, code));
	return (NULL);
}
