/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:45:15 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/21 14:15:40 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_size(char const *s, char c)
{
	int	size;
	int	is_separator;

	is_separator = 1;
	size = 0;
	while (*s)
	{
		if (*s == c)
			is_separator = 1;
		else
		{
			if (is_separator)
				size++;
			is_separator = 0;
		}
		s++;
	}
	return (size);
}

static char	*ft_split_chunk(char const *s, char c)
{
	int			len;
	char const	*start;
	char		*chunk;

	start = s;
	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	chunk = malloc(len + 1);
	if (chunk)
		ft_strlcpy(chunk, start, len + 1);
	return (chunk);
}

static void	ft_split_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static void	ft_split_fill(char **dest, char const *s, char c)
{
	int		i;
	int		is_separator;

	is_separator = 1;
	i = 0;
	while (*s)
	{
		if (*s == c)
			is_separator = 1;
		else
		{
			if (is_separator)
			{
				dest[i] = ft_split_chunk(s, c);
				if (!dest[i])
					return (ft_split_free(dest));
				i++;
			}
			is_separator = 0;
		}
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**dest;

	size = ft_split_size(s, c);
	dest = malloc((size + 1) * sizeof(char *));
	if (dest)
	{
		dest[size] = NULL;
		if (size)
			ft_split_fill(dest, s, c);
	}
	return (dest);
}

/*
int	main(void)
{
	free(ft_split("hello!", ' '));
}
*/
