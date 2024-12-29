/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:44:57 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/13 12:51:47 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(src) + 1;
	dup = malloc(size);
	if (dup)
		ft_memcpy(dup, src, size);
	return (dup);
}
