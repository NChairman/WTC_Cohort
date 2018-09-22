/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:40:14 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 09:40:17 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static wchar_t		*second_letter_test_l(const char format, va_list ap)
{
	if (format == '%')
		return (to_str('%'));
	if (format == 'p')
		return (handle_unsigned((unsigned long)va_arg(ap, void *), 16, 0));
	if (format == 'u')
		return (handle_unsigned(va_arg(ap, long), 10, 0));
	if (format == 'U')
		return (handle_unsigned(va_arg(ap, long), 10, 0));
	if (format == 'o')
		return (handle_unsigned(va_arg(ap, long), 8, 0));
	if (format == 'O')
		return (handle_unsigned(va_arg(ap, long long), 8, 0));
	if (format == 'x')
		return (handle_unsigned(va_arg(ap, long), 16, 0));
	if (format == 'X')
		return (handle_unsigned(va_arg(ap, long long), 16, 1));
	return (NULL);
}

wchar_t				*test_for_int(const char format, va_list ap,\
					int *count)
{
	if (format == 'd' || format == 'i')
		return (ft_itoa_signed_ll(va_arg(ap, long), 10));
	if (format == 'D' || format == 'I')
		return (ft_itoa_signed_ll(va_arg(ap, long long), 10));
	if (format == 's' || format == 'S')
		return (ft_strdup_wchar_to_wchar(va_arg(ap, wchar_t *)));
	if (format == 'c' || format == 'C')
		return (to_str_w(va_arg(ap, wchar_t), count));
	if (format == 'b')
		return (handle_unsigned(va_arg(ap, long), 2, 0));
	return (second_letter_test_l(format, ap));
}

static wchar_t		*second_letter_test_ll(const char format, va_list ap)
{
	if (format == '%')
		return (to_str('%'));
	if (format == 'p')
		return (handle_unsigned(va_arg(ap, long long), 16, 0));
	if (format == 'u' || format == 'U')
		return (handle_unsigned(va_arg(ap, long long), 10, 0));
	if (format == 'o' || format == 'O')
		return (handle_unsigned(va_arg(ap, long long), 8, 0));
	if (format == 'x')
		return (handle_unsigned(va_arg(ap, long long), 16, 0));
	if (format == 'X')
		return (handle_unsigned(va_arg(ap, long long), 16, 1));
	return (NULL);
}

wchar_t				*test_with_cmp(const char format,\
					va_list ap, int *count)
{
	if (format == 'd' || format == 'i' || format == 'D' || format == 'I')
		return (ft_itoa_signed_ll(va_arg(ap, long long), 10));
	if (format == 's' || format == 'S')
		return (ft_strdup_wchar_to_wchar(va_arg(ap, wchar_t *)));
	if (format == 'c' || format == 'C')
		return (to_str_w(va_arg(ap, wchar_t), count));
	if (format == 'b')
		return (handle_unsigned(va_arg(ap, long long), 2, 0));
	return (second_letter_test_ll(format, ap));
}
