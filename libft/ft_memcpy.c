/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:44:55 by nkngweny          #+#    #+#             */
/*   Updated: 2018/05/24 09:14:05 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	n;

	d = (char *)dst;
	s = (char *)src;
	n = 0;
	while (n < len)
	{
		d[n] = s[n];
		n++;
	}
	return ((void *)d);
}
