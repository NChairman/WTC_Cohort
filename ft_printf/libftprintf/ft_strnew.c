/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:16:15 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/02 13:08:56 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*c;

	if ((c = (char *)malloc(sizeof(char) * (size + 1))))
		return ((char *)ft_memset((void *)c, '\0', size + 1));
	return (NULL);
}
