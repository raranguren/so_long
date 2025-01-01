/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:40 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/24 19:00:46 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef GET_NEXT_LINE_BUFFER_SIZE
#  define GET_NEXT_LINE_BUFFER_SIZE 10000
# endif

typedef struct s_buffer
{
	ssize_t	size;
	size_t	start;
	char	data[GET_NEXT_LINE_BUFFER_SIZE];
}	t_buffer;

typedef struct s_line
{
	size_t	len;
	int		complete;
	char	*str;
}	t_line;

char	*get_next_line(int fd);

#endif
