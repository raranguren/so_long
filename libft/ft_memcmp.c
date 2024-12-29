/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:31:59 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 23:21:13 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a, const void *b, size_t size)
{
	while (size)
	{
		if (*(char *)a != *(char *)b)
			return (*(unsigned char *)a - *(unsigned char *)b);
		a++;
		b++;
		size--;
	}
	return (0);
}
