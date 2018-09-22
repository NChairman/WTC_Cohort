/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:50:27 by nkngweny          #+#    #+#             */
/*   Updated: 2018/05/30 16:21:56 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0' && a < len)
	{
		b = 0;
		while ((needle[b] != '\0') && (needle[b] == haystack[a + b])
				&& (a + b) < len)
			b++;
		if (needle[b] == '\0')
			return ((char *)haystack + a);
		a++;
	}
	return (NULL);
}
