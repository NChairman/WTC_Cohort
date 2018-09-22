/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:09:56 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:27:42 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag(char **str, t_format **format)
{
	char	*s;
	char	*s1;
	char	*s_tmp;

	s = *str;
	s1 = ft_strdup("");
	while (ft_strchr(FLAGS, *s))
	{
		s_tmp = s1;
		if (*s == '#')
			(*format)->hash = 1;
		else if (*s == ' ')
			(*format)->space = 1;
		else if (*s == '+')
			(*format)->plus = 1;
		else if (*s == '-')
			(*format)->minus = 1;
		else
			(*format)->zero = 1;
		s1 = ft_strjoin(s_tmp, &s[0]);
		s++;
	}
	*str = s;
	(*format)->form = s1;
}

void	ft_pre(char **str, t_format **format)
{
	char	*s;

	(*format)->width = ft_atoi(*str);
	while (ft_isdigit(**str))
	{
		s = (*format)->form;
		(*format)->form = ft_strjoin(s, &(*str[0]));
		*str = *str + 1;
	}
}

void	ft_prec(char **str, t_format **format)
{
	char	*s;

	*str = *str + 1;
	(*format)->pre = ft_atoi(*str);
	while (ft_isdigit(**str))
	{
		s = (*format)->form;
		(*format)->form = ft_strjoin(s, &(*str[0]));
		*str = *str + 1;
	}
}

void	ft_con(char **str, t_format **format)
{
	if (ft_strchr(CON, **str))
	{
		(*format)->con_type = **str;
		*str = *str + 1;
		(*format)->valid = 1;
	}
	else
	{
		(*format)->con_type = '\0';
		(*format)->valid = 0;
	}
}
