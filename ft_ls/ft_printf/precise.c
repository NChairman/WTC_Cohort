/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:44:23 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:44:26 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*add_numbers_neg(wchar_t **str, int number)
{
	int		i;
	int		j;
	wchar_t *cpy;

	i = 0;
	j = 1;
	if (number < (ft_strlen_null(*str, 0) - 1))
		return (*str);
	cpy = (wchar_t *)malloc((2 + number) * sizeof(wchar_t));
	if (!cpy)
		exit(0);
	cpy[i++] = '-';
	while (i <= (number - ft_strlen_null(*str, 0) + 1))
		cpy[i++] = '0';
	while (i <= number)
		cpy[i++] = (*str)[j++];
	cpy[i] = '\0';
	free(*str);
	return (cpy);
}

static wchar_t	*new_prec_with_zero(wchar_t **str, int prec)
{
	wchar_t *cpy;
	int		j;
	int		h;

	h = 0;
	j = 0;
	if (prec == -1)
		return (*str);
	cpy = (wchar_t *)malloc((prec + 1) * sizeof(wchar_t));
	if (!cpy)
		exit(0);
	while (j < (prec - ft_strlen_null(*str, 0)))
		cpy[j++] = '0';
	while (j < prec)
		cpy[j++] = (*str)[h++];
	cpy[j] = '\0';
	free(*str);
	return (cpy);
}

static wchar_t	*wstr_precision(wchar_t **arg, int p)
{
	wchar_t *str;
	int		i;

	i = 0;
	if (p == -1)
	{
		str = (wchar_t *)malloc(1 * sizeof(wchar_t));
		if (!str)
			exit(0);
		str[0] = '\0';
	}
	else
	{
		str = (wchar_t*)malloc((p + 1) * sizeof(wchar_t));
		while (((p - (int)wchar_len((*arg)[i])) >= 0) && (*arg)[i])
		{
			str[i] = (*arg)[i];
			p = p - wchar_len((*arg)[i]);
			i++;
		}
	}
	str[i] = '\0';
	free(*arg);
	return (str);
}

static wchar_t	*str_precision(wchar_t **arg, int p)
{
	int		i;
	wchar_t *str;

	i = 0;
	if (p == -1)
	{
		str = (wchar_t *)malloc(1 * sizeof(wchar_t));
		if (!str)
			exit(0);
		str[0] = '\0';
		free(*arg);
		return (str);
	}
	while (p != i && (*arg)[i])
		i++;
	if ((*arg)[i])
	{
		str = (wchar_t *)malloc((p + 1) * sizeof(wchar_t));
		if (!str)
			exit(0);
		ft_strncpy_wchar(str, *arg, p);
		free(*arg);
		return (str);
	}
	return (*arg);
}

wchar_t			*handle_prec(wchar_t **arg, int p, const char letter)
{
	if ((letter == 'c' || p == 0 || letter == '%'\
	|| letter == 'C') && letter != 'p')
		return (*arg);
	if (letter == 's')
		return (str_precision(arg, p));
	if (letter == 'S')
		return (wstr_precision(arg, p));
	if ((p == -1 && ft_watoi(*arg) == 0) && valid_letter(letter) == 1)
		(*arg)[0] = '\0';
	else
	{
		if ((*arg)[0] == '-')
			*arg = add_numbers_neg(arg, p);
		else if (ft_strlen_null(*arg, 0) < p)
			*arg = new_prec_with_zero(arg, p);
	}
	return (*arg);
}
