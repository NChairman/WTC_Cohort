/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:20:36 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/19 15:10:18 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flags_two(int ac, char **av)
{
	int		i;
	char	*s_tmp;
	char	*s1_tmp;

	i = 1;
	s_tmp = ft_strdup("");
	while (i < ac)
	{
		s1_tmp = s_tmp;
		s1_tmp = ft_strcat(s1_tmp, " ");
		s_tmp = ft_strjoin(s1_tmp, av[i++]);
		free(s1_tmp);
	}
	ft_str_sys(s_tmp);
	free(s_tmp);
}
