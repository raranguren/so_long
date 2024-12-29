/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:30:36 by rarangur          #+#    #+#             */
/*   Updated: 2024/12/08 14:45:51 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_format_nbr(t_printf_config *config, char *src, char *prefix)
{
	char	*dest;
	char	*writer;
	int		zeroes;
	int		src_len_with_sign;

	dest = malloc(config->precision + config->min_field_width + 42);
	if (!dest)
		return (NULL);
	src_len_with_sign = ft_strlen(src);
	writer = dest;
	if (*src == '-')
		*writer++ = *src++;
	else if (config->positive_sign)
		*writer++ = config->positive_sign;
	if (config->use_prefix && *src != '0')
		while (*prefix)
			*writer++ = *prefix++;
	zeroes = config->precision - ft_strlen(src);
	if (config->nbr_filler && config->precision < 0 && !config->left_justify)
		zeroes = config->min_field_width - src_len_with_sign;
	while (zeroes-- > 0)
		*writer++ = '0';
	while (*src)
		*writer++ = *src++;
	return (*writer = '\0', dest);
}

int	ft_printf_ptr(t_printf_config *config, void *ptr)
{
	if (!ptr)
	{
		config->precision = -1;
		return (ft_printf_str(config, "(nil)"));
	}
	config->use_prefix = 1;
	return (ft_printf_base(config, (unsigned long)ptr, BASE16, "0x"));
}

int	ft_printf_nbr(t_printf_config *config, int nbr)
{
	char	*nbr_base;
	char	*nbr_formatted;
	int		len;

	if (nbr == 0 && config->precision == 0)
		return (ft_printf_str(config, ""));
	nbr_base = ft_itoa(nbr);
	if (!nbr_base)
		return (-1);
	nbr_formatted = _format_nbr(config, nbr_base, "");
	free(nbr_base);
	if (!nbr_formatted)
		return (-1);
	config->precision = -1;
	len = ft_printf_str(config, nbr_formatted);
	free(nbr_formatted);
	return (len);
}

int	ft_printf_base(t_printf_config *config, unsigned long nbr, \
		char *base, char *prefix)
{
	int		len;
	char	*nbr_base;
	char	*nbr_formatted;

	if (nbr == 0 && config->precision == 0)
		return (ft_printf_str(config, ""));
	nbr_base = ft_ultoa_base(nbr, base);
	if (!nbr_base)
		return (-1);
	nbr_formatted = _format_nbr(config, nbr_base, prefix);
	free(nbr_base);
	if (!nbr_formatted)
		return (-1);
	config->precision = -1;
	len = ft_printf_str(config, nbr_formatted);
	free(nbr_formatted);
	return (len);
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	buff[65];
	int		start;
	int		radix;

	radix = ft_strlen(base);
	if (radix < 2)
		return (NULL);
	start = radix;
	buff[start] = '\0';
	if (n == 0)
	{
		start--;
		buff[start] = '0';
	}
	while (n > 0)
	{
		start--;
		buff[start] = base[n % radix];
		n /= radix;
	}
	return (ft_strdup(&buff[start]));
}
