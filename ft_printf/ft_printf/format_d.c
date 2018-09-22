/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:09:53 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:23:12 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uhandle(t_format **format, va_list ap, int *nbr)
{
	char					*s_tmp;
	unsigned long long int	ui_tmp;

	if ((*format)->con_type == 'U')
		ui_tmp = (unsigned long)va_arg(ap, long int);
	else
	{
		if (ft_strequ((*format)->length_mod, "ll"))
			ui_tmp = va_arg(ap, unsigned long long);
		else if (ft_strequ((*format)->length_mod, "l"))
			ui_tmp = va_arg(ap, unsigned long);
		else if (ft_strequ((*format)->length_mod, "hh"))
			ui_tmp = va_arg(ap, unsigned int) & 0xFF;
		else if (ft_strequ((*format)->length_mod, "h"))
			ui_tmp = va_arg(ap, unsigned int) & 0xFFFF;
		else if (ft_strequ((*format)->length_mod, "j"))
			ui_tmp = va_arg(ap, uintmax_t);
		else if (ft_strequ((*format)->length_mod, "z"))
			ui_tmp = va_arg(ap, size_t);
		else
			ui_tmp = va_arg(ap, unsigned int);
	}
	s_tmp = ft_itoa_base(ui_tmp, 10);
	*nbr = ft_fw_digit(format, &s_tmp);
	return (s_tmp);
}

char	*ft_digit(t_format **format, va_list ap, int *nbr)
{
	long long int	a;
	char			*str;

	a = 0;
	if (ft_strequ((*format)->length_mod, "ll"))
		a = va_arg(ap, long long);
	else if (ft_strequ((*format)->length_mod, "l") ||
			((*format)->con_type == 'D'))
		a = va_arg(ap, long);
	else if (ft_strequ((*format)->length_mod, "hh"))
		a = (char)va_arg(ap, int);
	else if (ft_strequ((*format)->length_mod, "h"))
		a = (short int)va_arg(ap, int);
	else if (ft_strequ((*format)->length_mod, "j"))
		a = va_arg(ap, intmax_t);
	else if (ft_strequ((*format)->length_mod, "z"))
		a = va_arg(ap, long long int);
	else
		a = va_arg(ap, int);
	str = ft_itoa(a);
	*nbr = ft_dformat(format, &str, a);
	return (str);
}
