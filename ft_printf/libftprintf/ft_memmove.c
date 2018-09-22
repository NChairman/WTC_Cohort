/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:51:37 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/02 12:56:04 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	i = 0;
	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if (s1 < d1)
		while (len--)
			d1[len] = s1[len];
	else
		while (i < len)
		{
			d1[i] = s1[i];
			i++;
		}
	return (dst);
}
