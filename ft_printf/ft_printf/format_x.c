/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:20:49 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 07:53:29 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xxhandle(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;
	int		i;

	s_tmp = ft_xhandle(format, ap, nbr);
	i = 0;
	while (s_tmp[i])
	{
		if (ft_isalpha(s_tmp[i]))
			s_tmp[i] = ft_toupper(s_tmp[i]);
		i++;
	}
	return (s_tmp);
}

char	*ft_xhandle(t_format **format, va_list ap, int *nbr)
{
	int						i;
	char					*s_tmp;
	unsigned long long int	ui_tmp;

	i = 0;
	if (ft_strequ((*format)->length_mod, "ll"))
		ui_tmp = va_arg(ap, unsigned long long);
	else if (ft_strequ((*format)->length_mod, "l"))
		ui_tmp = va_arg(ap, unsigned long);
	else if (ft_strequ((*format)->length_mod, "hh"))
		ui_tmp = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ((*format)->length_mod, "hh"))
		ui_tmp = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ((*format)->length_mod, "j"))
		ui_tmp = va_arg(ap, uintmax_t);
	else if (ft_strequ((*format)->length_mod, "z"))
		ui_tmp = va_arg(ap, size_t);
	else
		ui_tmp = va_arg(ap, unsigned int);
	s_tmp = ft_itoa_base(ui_tmp, 16);
	*nbr = ft_xformat(format, &s_tmp, ui_tmp);
	return (s_tmp);
}

char	*ft_ohandle(t_format **format, va_list ap, int *nbr)
{
	char					*s_tmp;
	unsigned long long int	o_tmp;

	if (ft_strequ((*format)->length_mod, "l"))
		o_tmp = va_arg(ap, unsigned long);
	else if (ft_strequ((*format)->length_mod, "ll"))
		o_tmp = va_arg(ap, unsigned long long);
	else if (ft_strequ((*format)->length_mod, "h"))
		o_tmp = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ((*format)->length_mod, "hh"))
		o_tmp = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ((*format)->length_mod, "j"))
		o_tmp = va_arg(ap, uintmax_t);
	else if (ft_strequ((*format)->length_mod, "z"))
		o_tmp = va_arg(ap, size_t);
	else
		o_tmp = va_arg(ap, unsigned int);
	s_tmp = ft_itoa_base(o_tmp, 8);
	*nbr = ft_oformat(format, &s_tmp, o_tmp);
	return (s_tmp);
}
