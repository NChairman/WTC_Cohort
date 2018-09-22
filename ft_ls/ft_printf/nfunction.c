/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfunction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:03:26 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/21 08:22:56 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				nfunction(va_list ap, wchar_t *str, wchar_t **arg)
{
	int *g;

	g = va_arg(ap, void *);
	*g = wstr_len(str);
	if (!arg)
		exit(-1);
	free(*arg);
}
