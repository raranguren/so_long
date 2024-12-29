/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:55:07 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 15:48:36 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*found;

	found = NULL;
	while (*str)
	{
		if (*str == (char)c)
			found = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (found);
}
