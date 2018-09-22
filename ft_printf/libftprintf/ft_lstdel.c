/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:25:38 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/03 16:29:35 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*n;
	t_list	*node;

	node = *alst;
	while (node)
	{
		n = node->next;
		del(node->content, node->content_size);
		free(node);
		node = n;
	}
	*alst = NULL;
}
