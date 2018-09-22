/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:37:48 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 09:37:52 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static wchar_t	*number_assign_ll(wchar_t *str, unsigned long long n,\
					int i, int base)
{
	wchar_t c;

	while ((n / base) >= 1)
	{
		c = '0';
		if ((n % base) >= 10 && base > 10)
			c = 'a' - 10;
		str[i] = ((n % base) + c);
		n = (n / base);
		i++;
	}
	c = '0';
	if (n >= 10 && base > 10)
		c = 'a' - 10;
	str[i] = (n + c);
	str[++i] = '\0';
	reverse(&str);
	return (str);
}

static wchar_t	*number_assign_signed_ll(wchar_t *str, long long n,\
					int i, int base)
{
	wchar_t c;

	while ((n / base) >= 1)
	{
		c = '0';
		if ((n % base) >= 10 && base > 10)
			c = 'a' - 10;
		str[i] = ((n % base) + c);
		n = (n / base);
		i++;
	}
	c = '0';
	if (n >= 10 && base > 10)
		c = 'a' - 10;
	str[i] = (n + c);
	str[++i] = '\0';
	reverse(&str);
	return (str);
}

static wchar_t	*number_assign_hexa_ll(wchar_t *str, unsigned long long n,\
					int i, int base)
{
	wchar_t c;

	while ((n / base) >= 1)
	{
		c = '0';
		if ((n % base) >= 10 && base > 10)
			c = 'A' - 10;
		str[i] = ((n % base) + c);
		n = (n / base);
		i++;
	}
	c = '0';
	if (n >= 10 && base > 10)
		c = 'A' - 10;
	str[i] = (n + c);
	str[++i] = '\0';
	reverse(&str);
	return (str);
}

wchar_t			*handle_unsigned(unsigned long long n, int base, int x)
{
	wchar_t				*str;
	int					i;
	unsigned long long	j;

	i = 0;
	if (base <= 0)
		return (NULL);
	str = (wchar_t *)malloc(100 * sizeof(wchar_t));
	if (!str)
		exit(0);
	if (!str)
		return (NULL);
	j = n;
	if (x == 0)
	{
		str = number_assign_ll(str, j, i, base);
	}
	else
		str = number_assign_hexa_ll(str, j, i, base);
	return (str);
}

wchar_t			*ft_itoa_signed_ll(long long n, int base)
{
	wchar_t		*str;
	int			i;
	long long	j;

	i = 0;
	if (base <= 0)
		return (NULL);
	str = malloc(72 * sizeof(wchar_t));
	if (!str)
		exit(0);
	if (n == LLONG_MIN)
	{
		return ((str = ft_strdup_wchar("-9223372036854775808")));
	}
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		i++;
	}
	j = n;
	str = number_assign_signed_ll(str, j, i, base);
	return (str);
}
