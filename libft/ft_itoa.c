/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:56:05 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/05 12:50:07 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_checksas(size_t *c, int *sign, int *v)
{
	*c = 1;
	if (*v < 0)
	{
		*sign = 0;
		*v = -(*v);
		(*c)++;
	}
	else
		*sign = 1;
}

char		*ft_itoa(int a)
{
	size_t	n;
	int		a1;
	char	*c;
	int		sign;

	if (a == 0)
		return (ft_strdup("0"));
	if (a == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_checksas(&n, &sign, &a);
	a1 = a;
	while (a1 >= 1 && n++)
		a1 /= 10;
	if (!(c = (char *)malloc(sizeof(char) * n)))
		return (NULL);
	n--;
	c[n--] = '\0';
	while (a >= 1)
	{
		c[n--] = (a % 10) + '0';
		a = a / 10;
	}
	if (sign == 0)
		c[n] = '-';
	return (c);
}
