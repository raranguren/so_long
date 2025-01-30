/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 01:03:33 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/30 22:59:10 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <time.h>

/*
 * Returns 0 unless a fixed interval of time has passed. 
 * The interval is defined by the variable ANIMATIONS_PER_MINUTE
 *
 */
int	tick(void)
{
	static clock_t	next_tick;
	static clock_t	interval;
	clock_t			now;

	if (!interval)
		interval = (CLOCKS_PER_SEC * 60) / ANIMATION_SPEED;
	now = clock();
	if (!next_tick)
	{
		next_tick = now + interval;
		return (0);
	}
	if (now < next_tick)
		return (0);
	next_tick += interval;
	return (1);
}
