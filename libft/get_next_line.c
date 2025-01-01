/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:18 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/26 09:34:37 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	init_line(t_line *line)
{
	line->complete = 0;
	line->str = malloc(1);
	if (line->str)
	{
		line->str[0] = '\0';
		line->len = 0;
	}
}

static char	*next_str_from_buffer(t_buffer *buff)
{
	size_t	len;
	size_t	i;
	size_t	buff_end;
	char	*str;

	buff_end = buff->start + buff->size;
	i = buff->start;
	while (i < buff_end && buff->data[i] != '\n')
		i++;
	if (i < buff_end && buff->data[i] == '\n')
		i++;
	len = i - buff->start;
	str = malloc(len + 1);
	if (str)
	{
		str[len] = '\0';
		ft_memcpy(str, buff->data + buff->start, len);
	}
	buff->size -= len;
	buff->start = i;
	return (str);
}

static void	build_line(t_line *line, char *src)
{
	char	*new_str;
	size_t	src_len;

	new_str = NULL;
	if (src)
	{
		src_len = ft_strlen(src);
		new_str = malloc(line->len + src_len + 1);
		if (new_str)
		{
			ft_memcpy(new_str, line->str, line->len);
			ft_memcpy(new_str + line->len, src, src_len);
			line->len += src_len;
			new_str[line->len] = '\0';
			line->complete = new_str[line->len - 1] == '\n';
		}
	}
	free(line->str);
	line->str = new_str;
}

char	*get_next_line(int fd)
{
	static t_buffer	buff;
	t_line			line;
	char			*chunk;

	if (fd < 0)
		return (NULL);
	init_line(&line);
	while (line.str && !line.complete)
	{
		if (buff.size <= 0)
		{
			buff.start = 0;
			buff.size = read(fd, buff.data, GET_NEXT_LINE_BUFFER_SIZE);
			if (buff.size <= 0)
				line.complete = 1;
			continue ;
		}
		chunk = next_str_from_buffer(&buff);
		build_line(&line, chunk);
		free(chunk);
	}
	if (line.str && *line.str && buff.size >= 0)
		return (line.str);
	free(line.str);
	return (NULL);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(int c, char **v)
{
	int		fd = 0;
	char	*s;

	if (c > 1)
		fd = open(v[1], O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	close(fd);
}
*/
