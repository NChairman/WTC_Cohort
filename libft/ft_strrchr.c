/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:40:50 by nkngweny          #+#    #+#             */
/*   Updated: 2018/05/29 13:47:03 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	size_t	j;

	s1 = (char *)s;
	j = ft_strlen(s1);
	while (j > 0 && (char)c != s1[j])
		j--;
	if (s1[j] == (char)c)
		return (s1 + j);
	return (NULL);
}
