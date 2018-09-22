/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaggings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:36:23 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 09:36:42 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*adding_flags(int hashtag, int zero, int minus)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(6 * sizeof(char));
	if (!str)
		exit(0);
	if (hashtag >= 1)
		str[i++] = '#';
	if (zero >= 1)
		str[i++] = '0';
	if (minus >= 1)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

static char		*adding_second_flags(char *str, int plus, int space)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (plus >= 1)
		str[i++] = '+';
	if (space >= 1)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

static char		*same_flags_second_part(const char *format, int *i, \
										char *str, int space)
{
	int plus;

	plus = 0;
	while (format[*i] == ' ' | format[*i] == '#' | format[*i] == '0'\
			| format[*i] == '-' | format[*i] == '+')
	{
		if (format[*i] == '+')
			plus++;
		else if (format[*i] == ' ')
			space++;
		++*i;
	}
	return (adding_second_flags(str, plus, space));
}

char			*handle_similar(const char *format, int *i,\
								int zero, int hashtag)
{
	int o;
	int minus;

	minus = 0;
	o = *i;
	while (format[o] == ' ' | format[o] == '#' | format[o] == '0'\
			| format[o] == '-' | format[o] == '+')
	{
		if (format[o] == '#')
			hashtag++;
		else if (format[o] == '0')
			zero++;
		else if (format[o] == '-')
			minus++;
		o++;
	}
	return (same_flags_second_part(format, i,\
			adding_flags(hashtag, zero, minus), 0));
}
