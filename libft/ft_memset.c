/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:38:39 by nkngweny          #+#    #+#             */
/*   Updated: 2018/05/24 16:01:27 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;
	char	*a;
	char	c1;

	n = 0;
	a = (char *)b;
	c1 = (unsigned char)c;
	while (n < len)
		a[n++] = c1;
	return (a);
}
