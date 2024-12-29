/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:51:47 by rarangur          #+#    #+#             */
/*   Updated: 2024/12/08 14:45:59 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(t_printf_config *config, char c)
{
	int	i;
	int	i_c;
	int	write_result;

	if (config->min_field_width <= 1)
		return (write(1, &c, 1));
	i_c = config->min_field_width - 1;
	if (config->left_justify)
		i_c = 0;
	i = 0;
	while (i < config->min_field_width)
	{
		if (i == i_c)
			write_result = write(1, &c, 1);
		else
			write_result = write(1, " ", 1);
		if (write_result < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_printf_str(t_printf_config *config, char *str)
{
	char	*truncated;
	char	*justified;
	int		len;

	if (!str && (config->precision >= 6 || config->precision < 0))
		return (ft_printf_str(config, "(null)"));
	else if (!str)
		return (ft_printf_str(config, ""));
	len = ft_strlen(str);
	if (len > config->precision && config->precision >= 0)
		len = config->precision;
	truncated = malloc(len + 1);
	if (!truncated)
		return (-1);
	ft_strlcpy(truncated, str, len + 1);
	justified = ft_str_justify(truncated, config->min_field_width, \
			' ', config->left_justify);
	free(truncated);
	if (!justified)
		return (-1);
	len = ft_strlen(justified);
	len = write(1, justified, len);
	free(justified);
	return (len);
}

/**
 * Changes the size of a string to at least 'min_field' length, 
 * filling the space with the 'filler' character.
 *
 * @param src Source string.
 * @param min_field Minimum size of the resulting string.
 * @param filler Value to fill the space when 'src' is smaller than 'min_field'.
 * @param align If not zero, align to the left (adds fillers after 'src').
 *
 * @return NULL if malloc fails, otherwise gives the formatted string.
 */
char	*ft_str_justify(char const *src, int min_field, char filler, int align)
{
	char	*dest;
	int		src_len;
	int		fill_len;

	src_len = ft_strlen(src);
	fill_len = min_field - src_len;
	if (fill_len <= 0 || !filler)
		return (ft_strdup(src));
	dest = malloc(src_len + fill_len + 1);
	if (!dest)
		return (NULL);
	if (align)
	{
		ft_memcpy(dest, src, src_len);
		ft_memset(dest + src_len, filler, fill_len);
	}
	else
	{
		ft_memset(dest, filler, fill_len);
		ft_memcpy(dest + fill_len, src, src_len);
	}
	dest[src_len + fill_len] = '\0';
	return (dest);
}
