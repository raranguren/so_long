/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:42:01 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/13 12:53:58 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		len;
	int		i;

	len = ft_strlen(s);
	map = malloc(1 + len);
	if (!map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
