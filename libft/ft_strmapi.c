/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:15:22 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/02 13:03:27 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int k, char c))
{
	unsigned int	i;
	unsigned int	j;
	char			*s1;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	if (!(s1 = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
