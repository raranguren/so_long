/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:52:23 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/12 11:24:45 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(size);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, size);
	ft_strlcat(dest, s2, size);
	return (dest);
}
