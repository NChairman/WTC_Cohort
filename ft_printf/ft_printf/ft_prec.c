/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:52:23 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:26:12 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wf_str(t_format **format, char **str)
{
	char	*s_tmp;
	char	*s1_tmp;
	int		i_tmp;
	int		i;
	int		j;

	s_tmp = *str;
	i_tmp = ft_strlen(s_tmp);
	j = 0;
	i = 0;
	if ((*format)->width < i_tmp)
		return (ft_strlen(*str));
	s1_tmp = ft_strnew((*format)->width);
	s1_tmp = ft_memset(s1_tmp, ' ', (*format)->width);
	if (!(*format)->minus)
		i = (*format)->width - ft_strlen(s_tmp);
	while (s1_tmp[i] && s_tmp[j])
		s1_tmp[i++] = s_tmp[j++];
	*str = s1_tmp;
	return (ft_strlen(*str));
}

int		ft_fw_digit(t_format **format, char **str)
{
	int		i;
	char	*s_tmp;

	i = 0;
	ft_wf_str(format, str);
	if ((*format)->zero && !((*format)->minus))
	{
		while (str[0][i])
			if (str[0][i++] == ' ')
				str[0][i - 1] = '0';
		if (((*format)->plus) && (s_tmp = ft_strchr(*str, '+'))
				&& !(*format)->hash)
		{
			s_tmp[0] = '0';
			if ((*format)->plus)
				str[0][0] = '+';
		}
		if ((s_tmp = ft_strchr(*str, '-')))
		{
			s_tmp[0] = '0';
			str[0][0] = '-';
		}
	}
	return (ft_strlen(*str));
}

int		ft_xformat(t_format **format, char **str, unsigned long long int x_tmp)
{
	int		nbr;
	char	*s_tmp;

	if ((*format)->hash && x_tmp != 0)
	{
		s_tmp = *str;
		*str = ft_strjoin("0x", s_tmp);
	}
	nbr = ft_fw_digit(format, str);
	if ((*format)->hash && (s_tmp = ft_strchr(*str, 'x'))
			&& (*format)->zero)
	{
		str[0][1] = s_tmp[0];
		if (!(*format)->minus)
			s_tmp[0] = '0';
	}
	return (nbr);
}

int		ft_oformat(t_format **format, char **str, unsigned long long int o_tmp)
{
	char	*s_tmp;

	if ((*format)->hash && o_tmp != 0)
	{
		s_tmp = *str;
		*str = ft_strjoin("0", s_tmp);
	}
	return (ft_fw_digit(format, str));
}

int		ft_dformat(t_format **format, char **str, long long int d_tmp)
{
	char	*s_tmp;
	int		nbr;

	if (((*format)->space) && d_tmp >= 0 && (!(*format)->plus))
	{
		s_tmp = *str;
		*str = ft_strjoin(" ", s_tmp);
	}
	if ((*format)->plus && d_tmp >= 0)
	{
		s_tmp = *str;
		*str = ft_strjoin("+", s_tmp);
	}
	nbr = ft_fw_digit(format, str);
	if ((s_tmp = ft_strchr(*str, '+')) && ((*format)->zero))
	{
		s_tmp[0] = '0';
		str[0][0] = '+';
	}
	return (nbr);
}
