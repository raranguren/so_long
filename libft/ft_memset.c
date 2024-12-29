/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:05:32 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 23:44:24 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *addr, int value, size_t size)
{
	char	*write;

	write = (char *)addr;
	while (size)
	{
		*write = (char)value;
		write++;
		size--;
	}
	return (addr);
}
