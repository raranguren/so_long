/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:14:11 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 23:32:18 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *addr, int c, size_t size)
{
	while (size)
	{
		if (*(unsigned char *)addr == (unsigned char)c)
			return ((void *)addr);
		addr++;
		size--;
	}
	return (NULL);
}
