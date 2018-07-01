/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:31:00 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/03 14:57:26 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	map = f(lst);
	head = map;
	lst = lst->next;
	while (lst)
	{
		map->next = f(lst);
		map = map->next;
		lst = lst->next;
	}
	return (head);
}
