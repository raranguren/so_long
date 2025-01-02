/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:36:01 by rarangur          #+#    #+#             */
/*   Updated: 2024/12/08 14:46:09 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_init_config(t_printf_config *config)
{
	*config = (t_printf_config){0};
	config->min_field_width = -1;
	config->precision = -1;
}

static const char	*_parse_sizes(t_printf_config *config, const char *f)
{
	if (*f >= '1' && *f <= '9')
		config->min_field_width = ft_atoi(f);
	while ((*f >= '0' && *f <= '9') || (*f == '.'))
		if (*f++ == '.')
			config->precision = ft_atoi(f);
	return (f);
}

static const char	*_parse_config(t_printf_config *config, const char *f)
{
	const char	*start;

	_init_config(config);
	start = f++;
	while (*f == '-' || *f == '0' || *f == '#' || *f == ' ' || *f == '+')
	{
		if (*f == '-')
			config->left_justify = 1;
		else if (*f == '0')
			config->nbr_filler = '0';
		else if (*f == '#')
			config->use_prefix = 1;
		else if (*f == ' ' || *f == '+')
			config->positive_sign = *f;
		f++;
	}
	f = _parse_sizes(config, f);
	if (ft_strchr("cspdiuxX%", *f))
		config->format_id = *f++;
	else
		f = start;
	return (f);
}

static int	_print_arg(const char **format, va_list *args)
{
	int				len;
	t_printf_config	conf;

	*format = _parse_config(&conf, *format);
	if (conf.format_id == 'c')
		len = ft_printf_char(&conf, va_arg(*args, int));
	else if (conf.format_id == 's')
		len = ft_printf_str(&conf, va_arg(*args, char *));
	else if (conf.format_id == 'p')
		len = ft_printf_ptr(&conf, va_arg(*args, void *));
	else if (conf.format_id == 'd' || conf.format_id == 'i')
		len = ft_printf_nbr(&conf, va_arg(*args, int));
	else if (conf.format_id == 'u')
		len = ft_printf_base(&conf, va_arg(*args, unsigned int), BASE10, "");
	else if (conf.format_id == 'x')
		len = ft_printf_base(&conf, va_arg(*args, unsigned int), BASE16, "0x");
	else if (conf.format_id == 'X')
		len = ft_printf_base(&conf, va_arg(*args, unsigned int), BASE16U, "0X");
	else if (conf.format_id == '%')
		return (write(1, "%", 1));
	else
		return (write(1, (*format)++, 1));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		len_total;

	if (!format)
		return (-1);
	len_total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len = _print_arg(&format, &args);
		else
			len = write(1, format++, 1);
		if (len < 0)
			return (-1);
		len_total += len;
	}
	va_end(args);
	return (len_total);
}
