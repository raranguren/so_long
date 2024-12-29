/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:56:39 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 23:01:08 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_initial;
	size_t	len;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_initial = ft_strlen(dest);
	len = len_initial;
	dest = &dest[len];
	while (*src && (len < size - 1))
	{
		*dest = *src;
		src++;
		dest++;
		len++;
	}
	if (len < size)
		*dest = '\0';
	if (size < len_initial)
		return (len_src + size);
	else
		return (len_src + len_initial);
}
