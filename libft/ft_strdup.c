/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:08:11 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/03 15:47:41 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	n;

	n = ft_strlen(s1) + 1;
	if (n <= 0)
		return (NULL);
	if (!(s = (char *)malloc(sizeof(char) * n)))
		return (NULL);
	return (char *)ft_memcpy(s, s1, n);
}
