/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:53:21 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/03 16:30:03 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t s)
{
	t_list *node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
	}
	else
	{
		node->content = ft_memalloc(s);
		ft_memcpy(node->content, content, s);
		node->content_size = s;
		node->next = NULL;
	}
	return (node);
}
