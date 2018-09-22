/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:58:41 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/05 13:12:35 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int b, size_t len)
{
	int		size;
	char	*c;
	int		i;
	int		b1;
	int		n;

	if (s)
	{
		i = 0;
		b1 = (int)b;
		n = (int)len;
		size = ft_strlen(s);
		if ((size - b1) < n || size <= 0 ||
				!(c = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < n)
			c[i++] = s[b1++];
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
