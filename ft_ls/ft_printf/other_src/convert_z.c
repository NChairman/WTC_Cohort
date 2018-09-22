/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:34:53 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 10:23:03 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static wchar_t			*handle_zero_neg(wchar_t **arg, int width, \
				wchar_t *cpy, char sign)
{
	int i;
	int j;

	i = 0;
	j = 1;
	cpy[i++] = sign;
	while ((width - i) > (ft_strlen_null(*arg, 0) - 1))
		cpy[i++] = '0';
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

static wchar_t			*zero_with_hash(wchar_t **arg, int width, char letter)
{
	int		i;
	wchar_t *cpy;
	int		j;
	int		count;

	i = 0;
	j = 2;
	count = 0;
	if (letter == 'p')
		letter = 'x';
	cpy = (wchar_t *)malloc((width + 1) * sizeof(wchar_t));
	cpy[i++] = '0';
	cpy[i++] = letter;
	while ((width - i + 2) > ft_strlen_null(*arg, 0))
		cpy[i++] = '0';
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

wchar_t					*zero_wchar(wchar_t **arg, int width, char letter)
{
	wchar_t *cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (width <= wstr_len(*arg))
		return (*arg);
	cpy = (wchar_t*)malloc((width + 1) * sizeof(wchar_t));
	if (!(*arg)[0] && letter == 'C')
		cpy[i++] = '\0';
	while ((width - i) > wstr_len(*arg))
		cpy[i++] = '0';
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	if (ft_strlen_null(*arg, 1) == 0 && letter == 'C')
		i--;
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

wchar_t					*second_part_zero(wchar_t **arg, int width, \
			char letter, wchar_t *cpy)
{
	int		i;
	int		j;
	int		c;

	initialize_three(&i, &c, &j);
	if (letter == 'c' && !(*arg)[0])
	{
		c = 1;
		cpy[i++] = '\0';
	}
	if (letter == 'S')
	{
		free(cpy);
		return (zero_wchar(arg, width, letter));
	}
	while ((width - i + c) > ft_strlen_null(*arg, c))
		cpy[i++] = '0';
	if ((*arg)[0] == ' ')
		j++;
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

wchar_t					*handle_zero(wchar_t **arg, int width, \
				char letter, int hashtag)
{
	wchar_t *cpy;

	if (ft_strlen_null(*arg, 0) >= width)
		return (*arg);
	if ((hashtag == 1 && (letter == 'x' || letter == 'X')) || letter == 'p')
		return (zero_with_hash(arg, width, letter));
	if ((*arg)[0] == '0')
		return (handle_mwidth(arg, width, letter));
	cpy = (wchar_t *)malloc((width + 2) * sizeof(wchar_t));
	if ((*arg)[0] == '+' || (*arg)[0] == '-')
		return (handle_zero_neg(arg, width, cpy, (*arg)[0]));
	return (second_part_zero(arg, width, letter, cpy));
}
