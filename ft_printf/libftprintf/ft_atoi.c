/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:07:00 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/02 13:05:16 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		n;
	int		len;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\f') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] == '0')
		i++;
	len = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i++] - '0');
		len++;
	}
	return (n * sign);
}
