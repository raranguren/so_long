/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:23:26 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 21:49:31 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*sprite_to_image(t_state *state, char code)
{
	if (code == '0')
		return (state->sprites.empty);
	if (code == '1')
		return (state->sprites.wall);
	if (code == 'P')
		return (state->sprites.player);
	if (code == 'C')
		return (state->sprites.collectible);
	if (code == 'E')
		return (state->sprites.exit);
	return (NULL);
}
