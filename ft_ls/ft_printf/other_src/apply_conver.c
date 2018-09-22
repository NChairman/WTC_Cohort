/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_conver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:33:47 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 09:33:51 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static wchar_t	*plus_conversion(wchar_t **arg, char letter)
{
	int		i;
	int		j;
	wchar_t *cpy;

	i = 0;
	j = 0;
	if (letter != 'd' && letter != 'i')
		return (*arg);
	if ((*arg)[i] != '-')
	{
		cpy = malloc((ft_strlen_null(*arg, 0) + 2) * sizeof(wchar_t));
		if (!cpy)
			exit(0);
		cpy[i] = '+';
		i++;
		while ((*arg)[j])
			cpy[i++] = (*arg)[j++];
		cpy[i] = '\0';
		free(*arg);
		return (cpy);
	}
	return (*arg);
}

static wchar_t	*space_conversion(wchar_t **arg, char letter)
{
	int		i;
	int		j;
	wchar_t	*cpy;

	i = 0;
	j = 0;
	if (letter != 'd' && letter != 'i')
		return (*arg);
	if ((*arg)[i] != '-')
	{
		cpy = malloc((ft_strlen_null(*arg, 0) + 2) * sizeof(wchar_t));
		if (!cpy)
			exit(0);
		cpy[i] = ' ';
		i++;
		while ((*arg)[j])
			cpy[i++] = (*arg)[j++];
		cpy[i] = '\0';
		free(*arg);
		return (cpy);
	}
	return (*arg);
}

static wchar_t	*minus_wchar(wchar_t **arg, int width)
{
	int		i;
	int		j;
	wchar_t	*cpy;

	j = 0;
	i = 0;
	if (width <= wstr_len(*arg))
		return (*arg);
	cpy = (wchar_t *)malloc((width + 1) * sizeof(wchar_t));
	if (!cpy)
		exit(0);
	while ((*arg)[i])
	{
		cpy[i] = (*arg)[i];
		i++;
	}
	while ((wstr_len(*arg) + j) < width)
	{
		j++;
		cpy[i++] = ' ';
	}
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

static wchar_t	*minus_conversion(wchar_t **arg, int width, char letter)
{
	int		i;
	wchar_t	*cpy;

	i = 0;
	if (!(*arg)[0] && (letter == 'c' || letter == 'C'))
		width--;
	if (letter == 'S')
		return (minus_wchar(arg, width));
	if (ft_strlen_null(*arg, i) >= width)
		return (*arg);
	cpy = (wchar_t *)malloc((width + 1) * sizeof(wchar_t));
	if (!cpy)
		exit(0);
	while ((*arg)[i])
	{
		cpy[i] = (*arg)[i];
		i++;
	}
	while (i < width)
		cpy[i++] = ' ';
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

wchar_t			*handle_flags(wchar_t **arg, char *flags, \
				char letter, int width)
{
	int hash;

	if (((hash = handle_hash(flags)) == 1 &&\
	letter != 'c' && letter != 'C') || letter == 'p')
		*arg = con_hash(arg, letter);
	if (handle_plus(flags) == 1)
		*arg = plus_conversion(arg, letter);
	else if (handle_sp(flags) == 1)
		*arg = space_conversion(arg, letter);
	if (handle_minus(flags, &width) == 1)
		*arg = minus_conversion(arg, width, letter);
	else if (handle_zeros(flags) == 1)
	{
		*arg = handle_zero(arg, width, letter, hash);
		if (handle_sp(flags) == 1)
			*arg = space_conversion(arg, letter);
	}
	else
		*arg = handle_mwidth(arg, width, letter);
	return (*arg);
}
