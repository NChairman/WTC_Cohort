/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:05:47 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/30 08:26:57 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_work(char *str, va_list ap, int *nbr)
{
	int		count;
	char	*tmp;
	char	*store;

	store = ft_strdup("");
	while (*str)
	{
		if (*str == '%')
		{
			tmp = store;
			str++;
			store = ft_strjoin(tmp, ft_format(&str, ap, &count));
			*nbr += count;
		}
		else
		{
			tmp = store;
			store = ft_strjoin(tmp, ft_format1(&str, &count));
			*nbr += count;
		}
		free(tmp);
	}
	return (store);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s_tmp;
	char		*store;
	int			size;
	int			i;

	i = 0;
	s_tmp = (char*)format;
	va_start(ap, format);
	store = ft_work(s_tmp, ap, &i);
	size = ft_strlen(store);
	write(1, store, size);
	va_end(ap);
	return (i);
}
