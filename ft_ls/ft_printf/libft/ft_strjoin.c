/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:31:39 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:49:18 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a1;
	int		a2;
	char	*c;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a1 = ft_strlen(s1);
	a2 = ft_strlen(s2);
	if (!(c = (char *)malloc(sizeof(char) * (a1 + a2 + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		c[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		c[i++] = s2[j++];
	c[i] = '\0';
	return (c);
}
