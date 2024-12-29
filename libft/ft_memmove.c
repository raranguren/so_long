/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:43:13 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/21 16:20:45 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*write;
	char	*read;
	int		step;

	if (!dest && !src)
		return (NULL);
	read = (char *)src;
	write = dest;
	step = 1;
	if (src < dest)
	{
		read += size - 1;
		write += size - 1;
		step = -1;
	}
	while (size)
	{
		*write = *read;
		read += step;
		write += step;
		size--;
	}
	return (dest);
}
