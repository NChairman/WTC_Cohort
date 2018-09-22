/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:05:39 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:24:06 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sstr(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;

	s_tmp = va_arg(ap, char*);
	if (s_tmp == NULL)
		s_tmp = ft_strdup("(null)");
	*nbr = ft_wf_str(format, &s_tmp);
	return (s_tmp);
}

char	*ft_chandle(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;

	s_tmp = ft_strnew(1);
	s_tmp[0] = (char)va_arg(ap, int);
	if (!ft_isprint(s_tmp[0]))
		s_tmp[0] = '.';
	*nbr = ft_wf_str(format, &s_tmp);
	return (s_tmp);
}

char	*ft_wstr(t_format **format, va_list ap, int *nbr)
{
	char	*str;
	char	*s_tmp;
	char	*s_tmp1;
	int		st_tmp;
	wchar_t	*ws_tmp;

	*nbr = 0;
	str = ft_strdup("");
	ws_tmp = va_arg(ap, wchar_t*);
	if (ws_tmp == NULL)
		ws_tmp = (wchar_t*)ft_strdup("(null)");
	st_tmp = sizeof(ws_tmp) / 2;
	while (st_tmp > 0)
	{
		nbr++;
		s_tmp = str;
		s_tmp1 = ft_constr(*ws_tmp++);
		str = ft_strjoin(s_tmp, s_tmp1);
		free(s_tmp);
		free(s_tmp1);
		st_tmp--;
	}
	ft_wf_str(format, &str);
	return (str);
}

char	*ft_constr(wchar_t chr)
{
	char	*s_tmp;

	s_tmp = ft_strnew(4);
	if (chr <= 0x7F)
		s_tmp[0] = chr;
	else if (chr <= 0x7FF)
	{
		s_tmp[0] = (chr >> 6) + 0xC0;
		s_tmp[1] = (chr & 0x3F) + 0x80;
	}
	else if (chr <= 0xFFFF)
	{
		s_tmp[0] = (chr >> 12) + 0xE0;
		s_tmp[1] = ((chr >> 6) & 0x3F) + 0x80;
		s_tmp[2] = (chr & 0x3F) + 0x80;
	}
	else
	{
		s_tmp[0] = (chr >> 18) + 0xF0;
		s_tmp[1] = ((chr >> 12) & 0x3F) + 0x80;
		s_tmp[2] = ((chr & 6) + 0x3F) + 0x80;
		s_tmp[3] = (chr & 0x3F) + 0x80;
	}
	return (s_tmp);
}

char	*ft_wchandle(t_format **format, va_list ap, int *nbr)
{
	char	*s_tmp;
	wchar_t	wc_tmp;

	s_tmp = NULL;
	*nbr = *nbr;
	if ((*format)->con_type == 'C')
	{
		wc_tmp = va_arg(ap, wchar_t);
		s_tmp = ft_constr(wc_tmp);
		*nbr = 1;
	}
	ft_wf_str(format, &s_tmp);
	return (s_tmp);
}
