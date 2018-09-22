/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:42:41 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:24:54 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handle2(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;

	if ((*format)->con_type == 'X')
		s_tmp = ft_xxhandle(format, ap, nbr);
	else if ((*format)->con_type == 'x')
		s_tmp = ft_xhandle(format, ap, nbr);
	else if ((*format)->con_type == '%')
	{
		s_tmp = ft_strdup("%");
		*nbr = ft_wf_str(format, &s_tmp);
	}
	else
		s_tmp = (*format)->form;
	return (s_tmp);
}

char	*ft_handle(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;

	if ((*format)->con_type == 'D')
		s_tmp = ft_digit(format, ap, nbr);
	else if ((*format)->con_type == 's')
		s_tmp = ft_sstr(format, ap, nbr);
	else if ((*format)->con_type == 'S')
		s_tmp = ft_wstr(format, ap, nbr);
	else if ((*format)->con_type == 'd' || (*format)->con_type == 'i')
		s_tmp = ft_digit(format, ap, nbr);
	else if ((*format)->con_type == 'u' || (*format)->con_type == 'U')
		s_tmp = ft_uhandle(format, ap, nbr);
	else if ((*format)->con_type == 'o' || (*format)->con_type == 'O')
		s_tmp = ft_ohandle(format, ap, nbr);
	else if ((*format)->con_type == 'p')
		s_tmp = ft_phandle(format, ap, nbr);
	else if ((*format)->con_type == 'c')
		s_tmp = ft_chandle(format, ap, nbr);
	else if ((*format)->con_type == 'C')
		s_tmp = ft_wchandle(format, ap, nbr);
	else
		s_tmp = ft_handle2(format, ap, nbr);
	return (s_tmp);
}
