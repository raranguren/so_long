/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:51:29 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/12 13:27:32 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *str, const char *small, size_t size)
{
	while (size && *small)
	{
		if (*str != *small)
			return (0);
		str++;
		small++;
		size--;
	}
	if (*small)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *small, size_t size)
{
	if (!*small)
		return ((char *)big);
	while (size && *big)
	{
		if (is_match(big, small, size))
			return ((char *)big);
		size--;
		big++;
	}
	return (NULL);
}
