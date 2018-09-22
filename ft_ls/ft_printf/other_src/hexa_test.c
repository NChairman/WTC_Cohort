/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:39:31 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 10:22:30 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static wchar_t		*second_letter_test_h(const char format, va_list ap)
{
	if (format == '%')
		return (to_str('%'));
	if (format == 'p')
		return (handle_unsigned((unsigned long)va_arg(ap, void *), 16, 0));
	if (format == 'u')
		return (handle_unsigned((unsigned short)va_arg(ap, int), 10, 0));
	if (format == 'U')
		return (handle_unsigned(va_arg(ap, long), 10, 0));
	if (format == 'o')
		return (handle_unsigned((unsigned short)va_arg(ap, int), 8, 0));
	if (format == 'O')
		return (handle_unsigned(va_arg(ap, int), 8, 0));
	if (format == 'x')
		return (handle_unsigned((unsigned short)va_arg(ap, int), 16, 0));
	if (format == 'X')
		return (handle_unsigned((unsigned short)va_arg(ap, int), 16, 1));
	return (NULL);
}

wchar_t				*test_for_hex(const char format,\
					va_list ap, int *count)
{
	if (format == 'd' || format == 'i')
		return (ft_itoa_signed_ll((short)va_arg(ap, int), 10));
	if (format == 'D' || format == 'I')
		return (ft_itoa_signed_ll(va_arg(ap, long long), 10));
	if (format == 's')
		return (ft_strdup_wchar(va_arg(ap, char *)));
	if (format == 'S')
		return (ft_strdup_wchar_to_wchar(va_arg(ap, wchar_t *)));
	if (format == 'c')
		return (to_str((char)va_arg(ap, int)));
	if (format == 'C')
		return (to_str_w(va_arg(ap, wchar_t), count));
	if (format == 'b')
		return (handle_unsigned((short)va_arg(ap, int), 2, 0));
	return (second_letter_test_h(format, ap));
}

static wchar_t		*second_letter_test_hh(const char format, va_list ap)
{
	if (format == '%')
		return (to_str('%'));
	if (format == 'p')
		return (handle_unsigned((unsigned long)va_arg(ap, void *), 16, 0));
	if (format == 'u')
		return (handle_unsigned((unsigned char)va_arg(ap, int), 10, 0));
	if (format == 'U')
		return (handle_unsigned((unsigned short)va_arg(ap, int), 10, 0));
	if (format == 'o')
		return (handle_unsigned((unsigned char)va_arg(ap, int), 8, 0));
	if (format == 'O')
		return (handle_unsigned((unsigned short)va_arg(ap, int), 8, 0));
	if (format == 'x')
		return (handle_unsigned((unsigned char)va_arg(ap, int), 16, 0));
	if (format == 'X')
		return (handle_unsigned((unsigned char)va_arg(ap, int), 16, 1));
	return (NULL);
}

wchar_t				*test_with_cmp1(const char format,\
				va_list ap, int *count)
{
	if (format == 'd' || format == 'i')
		return (ft_itoa_signed_ll((char)va_arg(ap, int), 10));
	if (format == 'D' || format == 'I')
		return (ft_itoa_signed_ll(va_arg(ap, long long), 10));
	if (format == 'S')
		return (ft_strdup_wchar_to_wchar(va_arg(ap, wchar_t *)));
	if (format == 's')
		return (ft_strdup_wchar(va_arg(ap, char *)));
	if (format == 'c')
		return (to_str((char)va_arg(ap, int)));
	if (format == 'C')
		return (to_str_w(va_arg(ap, wchar_t), count));
	if (format == 'b')
		return (handle_unsigned((char)va_arg(ap, int), 2, 0));
	return (second_letter_test_hh(format, ap));
}
