/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:37:49 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/21 16:20:20 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*write;

	if (!dest && !src)
		return (NULL);
	write = dest;
	while (size)
	{
		*write = *(char *)src;
		write++;
		src++;
		size--;
	}
	return (dest);
}
