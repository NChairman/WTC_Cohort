/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:22:00 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/05 16:09:35 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	j--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
		j--;
	if (!ft_strsub(s, i, (j - i + 1)))
		return (NULL);
	return (ft_strsub(s, i, (j - i + 1)));
}
