/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:55:57 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/05 16:07:59 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			n;

	n = 0;
	if (len == 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n < len)
	{
		d[n] = s[n];
		if (s[n++] == (unsigned char)c)
			return ((void *)(dest + n));
	}
	return (NULL);
}
