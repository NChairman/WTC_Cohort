/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:42:19 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:42:23 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_end(wchar_t **str, char **nformat, int count, va_list ap)
{
	free(*nformat);
	va_end(ap);
	return (ft_putwstr(str, count));
}

wchar_t				*ft_test(const char *format, va_list ap,\
					int *i, int *count)
{
	int		p;
	int		width;
	wchar_t *arg;
	char	*flags;

	flags = handle_similar(format, i, 0, 0);
	if (flags != NULL)
	{
		width = handle_width(format, i, ap);
		p = precision(format, i, ap);
		arg = handle_cflags(format, ap, i, count);
		if (!arg && (format[*i] == 's' || format[*i] == 'S'))
			return (ft_strdup_wchar("(null)"));
		if (!arg || (format[*i] == 'C' && wchar_len(arg[0]) == -1))
			return (NULL);
		arg = handle_prec(&arg, p, format[*i]);
		arg = handle_flags(&arg, flags, format[*i], width);
		free(flags);
		flags = NULL;
		return (arg);
	}
	return (NULL);
}

static void			initialize(wchar_t **str, char *nformat, int *i, int *count)
{
	*i = 0;
	*count = 0;
	*str = ft_wcharnew(*str, 1);
	*str = changing_malloc(str, nformat, i, *count);
}

int					ft_printf_second_part(char **nformat, va_list ap)
{
	wchar_t *str;
	int		i;
	int		count;
	wchar_t *arg;

	initialize(&str, *nformat, &i, &count);
	while ((*nformat)[i])
	{
		str = changing_malloc(&str, *nformat, &i, count);
		if ((*nformat)[i] == '%')
		{
			++i;
			if ((*nformat)[i] == 'N')
				arg = ft_itoa_signed_ll(wstr_len(str), 10);
			else
				arg = ft_test(*nformat, ap, &i, &count);
			if ((*nformat)[i] == 'n')
				nfunction(ap, str, &arg);
			else
				str = add_arg(&str, &arg, (*nformat)[i], &count);
			if ((*nformat)[i])
				++i;
		}
	}
	return (ft_end(&str, nformat, count, ap));
}

int					ft_printf(const char *format, ...)
{
	va_list ap;
	char	*nformat;

	if (!format)
		return (-1);
	nformat = call_color(format);
	va_start(ap, format);
	return (ft_printf_second_part(&nformat, ap));
}
