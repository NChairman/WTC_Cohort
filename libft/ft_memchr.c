/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:41:16 by nkngweny          #+#    #+#             */
/*   Updated: 2018/05/29 17:10:39 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*c1;
	size_t			n;

	n = 0;
	c1 = (unsigned char *)s;
	while (n < len)
	{
		if (c1[n] == (unsigned char)c)
			return (c1 + n);
		n++;
	}
	return (NULL);
}
