/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:57:37 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/12 13:35:27 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = 0;
	while (s1[len])
		len++;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	return (ft_substr(s1, 0, len));
}
