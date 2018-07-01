/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:27:21 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/02 13:03:55 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	d1;

	i = 0;
	d1 = ft_strlen(s1);
	if (((sizeof(s1) - d1) < n) && (s1 == NULL || s2 == NULL))
		return (NULL);
	if (s2[0] == '\0')
		return (s1);
	while (s2[i] != '\0' && i < n)
		s1[d1++] = s2[i++];
	if (s1[d1] != '\0')
		s1[d1] = '\0';
	return (s1);
}
