/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:39:58 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:24:31 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_phandle(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;
	char	*s_tmp1;
	size_t	i;

	*format = *format;
	i = 0;
	s_tmp = va_arg(ap, char*);
	s_tmp1 = ft_strdup("0x");
	ft_strcat(s_tmp1, ft_itoa_base((unsigned long int)s_tmp, 16));
	*nbr = ft_strlen(s_tmp1);
	return (s_tmp1);
}
