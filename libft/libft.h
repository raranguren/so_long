/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:21:08 by rarangur          #+#    #+#             */
/*   Updated: 2024/12/08 15:39:26 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "get_next_line.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *addr, int value, size_t size);
void	ft_bzero(void *addr, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *a, const char *b, size_t len);
void	*ft_memchr(const void *addr, int c, size_t size);
int		ft_memcmp(const void *a, const void *b, size_t size);
char	*ft_strnstr(const char *big, const char *small, size_t size);
int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//
// ft_printf
//
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

typedef struct s_printf_config
{
	int		min_field_width;
	int		precision;
	int		left_justify;
	char	nbr_filler;
	char	txt_filler;
	char	positive_sign;
	char	format_id;
	int		use_prefix;
}	t_printf_config;

int		ft_printf(const char *format, ...);

int		ft_printf_char(t_printf_config *config, char c);
int		ft_printf_str(t_printf_config *config, char *str);
int		ft_printf_ptr(t_printf_config *config, void *ptr);
int		ft_printf_nbr(t_printf_config *config, int nbr);
int		ft_printf_base(t_printf_config *config, unsigned long nbr, \
				char *base, char *prefix);

char	*ft_ultoa_base(unsigned long n, char *base);
char	*ft_str_justify(char const *src, int min_field, char filler, int align);

#endif
