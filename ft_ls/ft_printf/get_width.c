/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:43:04 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:43:12 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_width(const char *str, int *i, va_list ap)
{
	int		j;
	char	*width;

	j = 0;
	if (str[*i] == '*')
	{
		++*i;
		return (va_arg(ap, int));
	}
	width = (char *)malloc(11 * sizeof(char));
	if (!width)
		exit(0);
	while ((str[*i] >= '0') && (str[*i] <= '9'))
	{
		width[j++] = str[*i];
		++*i;
	}
	width[j] = '\0';
	j = ft_atoi(width);
	free(width);
	return (j);
}

int				wstr_len(wchar_t *str)
{
	size_t	i;
	size_t	sum;
	size_t	j;
	wchar_t *tmp;

	j = 0;
	sum = 0;
	while (str[j])
	{
		tmp = handle_unsigned(str[j], 2, 0);
		i = ft_strlen_null(tmp, 0);
		if (i <= 7)
			i = 1;
		else if (i <= 11)
			i = 2;
		else if (i <= 16)
			i = 3;
		else
			i = 4;
		sum = i + sum;
		j++;
		free(tmp);
	}
	return ((int)sum);
}

wchar_t			*wchar_width(wchar_t **arg, int width, int letter)
{
	wchar_t *cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (width <= wstr_len(*arg))
		return (*arg);
	cpy = (wchar_t*)malloc((width + 1) * sizeof(wchar_t));
	if (!cpy)
		exit(0);
	if (!(*arg)[0] && letter == 'C')
		cpy[i++] = '\0';
	while ((width - i) > wstr_len(*arg))
		cpy[i++] = ' ';
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	if (ft_strlen_null(*arg, 1) == 0 && letter == 'C')
		i--;
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

wchar_t			*handle_mwidth(wchar_t **arg, int width, char letter)
{
	int		i;
	int		j;
	wchar_t *cpy;

	j = 0;
	i = 0;
	if (letter == 'S' || letter == 'C')
		return (wchar_width(arg, width, letter));
	if (ft_strlen_null(*arg, 0) >= width)
		return (*arg);
	cpy = (wchar_t *)malloc((width + 1) * sizeof(wchar_t));
	if (!cpy)
		exit(0);
	if (!(*arg)[0] && letter == 'c')
		cpy[i++] = '\0';
	while ((width - i) > ft_strlen_null(*arg, 0))
		cpy[i++] = ' ';
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	if (ft_strlen_null(*arg, 1) == 0 && letter == 'c')
		i--;
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}
