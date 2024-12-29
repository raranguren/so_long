/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:22:38 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 18:39:08 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;
	char	*dest;

	while (start && *s)
	{
		start--;
		s++;
	}
	max_len = ft_strlen(s);
	if (len > max_len)
		len = max_len;
	dest = malloc(len + 1);
	if (dest)
	{
		ft_memcpy(dest, s, len);
		dest[len] = '\0';
	}
	return (dest);
}
