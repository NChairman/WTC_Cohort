/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:48:25 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:25:06 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lmod(char **str, t_format **format)
{
	if (str[0][0] == 'h' && str[0][1] == 'h')
	{
		(*format)->length_mod = ft_strdup("hh");
		*str = *str + 2;
	}
	else if (str[0][0] == 'h')
	{
		*str = *str + 1;
		(*format)->length_mod = ft_strdup("h");
	}
	else if (str[0][0] == 'l' && str[0][1] == 'l')
	{
		(*format)->length_mod = ft_strdup("ll");
		*str = *str + 2;
	}
	else if (str[0][0] == 'l')
	{
		*str = *str + 1;
		(*format)->length_mod = ft_strdup("l");
	}
	else
		ft_l_mod(str, format);
}

void	ft_l_mod(char **str, t_format **format)
{
	if (str[0][0] == 'j')
	{
		(*format)->length_mod = ft_strdup("j");
		*str = *str + 1;
	}
	else if (str[0][0] == 'z')
	{
		(*format)->length_mod = ft_strdup("z");
		*str = *str + 1;
	}
}
