/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unicodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:43:37 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:43:40 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mask_unicode_2(unsigned int v)
{
	unsigned int o;
	unsigned int o2;

	o = v >> 6;
	o2 = v - (o << 6);
	o = o + 192;
	o2 = o2 + 128;
	write(1, &o, 1);
	write(1, &o2, 1);
	return (2);
}

int	mask_unicode_3(unsigned int v)
{
	unsigned int o1;
	unsigned int o2;
	unsigned int o3;
	unsigned int temp;

	o1 = v >> 6;
	temp = o1;
	o1 = o1 >> 6;
	temp = temp << 6;
	o3 = v - (temp);
	temp = v - ((o1 << 12) + o3);
	o3 = o3 + 128;
	o1 = o1 + 224;
	o2 = (temp >> 6) + 128;
	write(1, &o1, 1);
	write(1, &o2, 1);
	write(1, &o3, 1);
	return (3);
}

int	mask_unicode_4(unsigned int v)
{
	unsigned int o1;
	unsigned int o2;
	unsigned int o3;
	unsigned int o4;

	o4 = v >> 6;
	o1 = v - (o4 << 6);
	o4 = o4 >> 6;
	o2 = v - ((o4 << 12) + o1);
	o4 = o4 >> 6;
	o3 = v - ((o4 << 18) + o1 + o2);
	o2 = (o2 >> 6) + 128;
	o3 = (o3 >> 12) + 128;
	o1 = o1 + 128;
	o4 = o4 + 240;
	write(1, &o4, 1);
	write(1, &o3, 1);
	write(1, &o2, 1);
	write(1, &o1, 1);
	return (4);
}
