/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:36:54 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/12 10:11:53 by rarangur         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	str[12];
	int		i;

	len = ft_itoa_len(n);
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
	ft_putstr_fd(str, fd);
}
