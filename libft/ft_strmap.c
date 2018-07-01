/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:09 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/02 13:03:11 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char k))
{
	int		i;
	int		j;
	char	*c;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	if (!(c = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		c[i] = (*f)(s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
