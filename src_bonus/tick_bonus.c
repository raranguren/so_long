/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 01:03:33 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/29 03:44:39 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <time.h>

/*
 * Returns 1 only when enough time has passed to animate the sprites. 
 * It regularly checks the system time to maintain the speed.
 */
int	tick(void)
{
	static int		loops_this_tick;
	static int		loops_this_second;
	static int		loops_per_tick = 10000;
	static time_t	before;
	static time_t	now;

	loops_this_tick++;
	if (loops_this_tick % 1000 == 0)
	{
		time(&now);
		if (!before)
			before = now;
	}
	if (now > before)
	{
		loops_per_tick = ((loops_this_second + loops_this_tick) * 60 \
						 / ANIMATION_SPEED / (now - before) \
						 + loops_per_tick) / (now - before + 1);
		loops_this_second = 0;
		before = now;
		ft_printf("Speed %i %i\n", loops_per_tick, loops_per_tick * ANIMATION_SPEED / 60);
	}
	if (loops_this_tick > loops_per_tick)
	{
		loops_this_second += loops_this_tick;
		loops_this_tick = 0;
	}
	return (loops_this_tick == 0);
}
