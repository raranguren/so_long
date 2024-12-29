/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:03:06 by rarangur          #+#    #+#             */
/*   Updated: 2024/11/21 12:59:53 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*elem;
	void	*content;

	map = NULL;
	content = NULL;
	while (lst)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			ft_lstclear(&map, del);
			break ;
		}
		ft_lstadd_back(&map, elem);
		lst = lst->next;
	}
	return (map);
}
