/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:26:35 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/16 15:30:19 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_sep(char const *s, char c)
{
	int		k;
	int		i;

	k = 1;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			k++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	char		**p;
	int			k;

	i = 0;
	if (!s || !(p = (char **)malloc(sizeof(char *) * ft_sep(s, c) + 1)))
		return (NULL);
	while (s[i] == c)
		i++;
	j = 0;
	while (s[i])
	{
		k = i;
		while (s[i] != c && s[i])
			i++;
		if (i - k >= 0)
			if (!(p[j++] = ft_strsub(s, k, i - k)))
				return (NULL);
		while (s[i] == c && s[i])
			i++;
	}
	p[j] = NULL;
	return (p);
}
