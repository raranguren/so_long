/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:02:58 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/15 18:48:09 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	len = ft_itoa_len(n);
	str = malloc(len + 1);
	if (str)
	{
		str[0] = '-';
		str[len] = '\0';
		i = len - 1;
		str[i] = '0';
		if (n > 0)
			n = -n;
		while (n < 0)
		{
			str[i] = '0' - (n % 10);
			i--;
			n /= 10;
		}
	}
	return (str);
}
