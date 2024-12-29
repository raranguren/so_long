/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:32:28 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/12 07:40:43 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	new_size;

	new_size = 1;
	while (*src && new_size < size)
	{
		*dest = *src;
		dest++;
		src++;
		new_size++;
	}
	if (size)
		*dest = '\0';
	while (*src++)
		new_size++;
	return (new_size - 1);
}
