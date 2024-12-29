/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:50:45 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 17:05:16 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*addr;
	size_t	size_total;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (INT_MAX / count < size)
		return (NULL);
	size_total = count * size;
	addr = malloc(size_total);
	if (addr)
		ft_bzero(addr, size_total);
	return (addr);
}
