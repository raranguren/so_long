/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:49:06 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/13 12:54:04 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t len)
{
	while (len && *a && *a == *b)
	{
		len--;
		a++;
		b++;
	}
	if (len)
		return ((unsigned char)*a - (unsigned char)*b);
	return (0);
}
