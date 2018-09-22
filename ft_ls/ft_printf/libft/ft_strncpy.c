/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:44:46 by ukhavham          #+#    #+#             */
/*   Updated: 2018/08/20 10:16:03 by ukhavham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strncpy_wchar(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
