/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:32:36 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 07:54:28 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_validity(char **str, t_format **format)
{
	ft_flag(str, format);
	ft_pre(str, format);
	if (*str[0] == '.')
		ft_prec(str, format);
	ft_lmod(str, format);
	ft_con(str, format);
}

void	ft_init_format(t_format **format)
{
	(*format)->width = -1;
	(*format)->pre = -1;
	(*format)->space = 0;
	(*format)->hash = 0;
	(*format)->minus = 0;
	(*format)->plus = 0;
	(*format)->zero = 0;
	(*format)->valid = 0;
	(*format)->con_type = '\0';
	(*format)->length_mod = ft_strdup("");
	(*format)->form = ft_strdup("");
}

char	*ft_format(char **str, va_list ap, int *nbr)
{
	t_format	*tmp;

	tmp = (t_format*)malloc(sizeof(t_format));
	ft_init_format(&tmp);
	ft_validity(str, &tmp);
	return (ft_handle(&tmp, ap, nbr));
}

char	*ft_format1(char **str, int *nbr)
{
	char	*s;

	s = ft_strnew(2);
	if (**str == 96)
	{
		s[0] = 96;
		s[1] = *str[1];
		*str = *str + 2;
	}
	else
	{
		s[0] = str[0][0];
		*str = *str + 1;
	}
	*nbr = 1;
	return (s);
}
