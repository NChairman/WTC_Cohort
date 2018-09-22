/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:37:05 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 09:37:08 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static wchar_t        *second_test_conv(const char *format, va_list ap, \
                                        int *i, int *count)
{
    if (format[*i] == 'j')
    {
        ++*i;
        return (test_with_cmp2(format[*i], ap, count));
    }
    else if (format[*i] == 'z')
    {
        ++*i;
        return (test_with_z(format[*i], ap, count));
    }
    else
        return (first_test(format[*i], ap, count));
}

wchar_t                *handle_cflags(const char *format, va_list ap, \
                                         int *i, int *count)
{
    if (format[*i] == 'l')
    {
        ++*i;
        if (format[*i] == 'l')
        {
            ++*i;
            return (test_with_cmp(format[*i], ap, count));
        }
        return (test_for_int(format[*i], ap, count));
    }
    else if (format[*i] == 'h')
    {
        ++*i;
        if (format[*i] == 'h')
        {
            ++*i;
            return (test_with_cmp1(format[*i], ap, count));
        }
        return (test_for_hex(format[*i], ap, count));
    }
    else
        return (second_test_conv(format, ap, i, count));
}

