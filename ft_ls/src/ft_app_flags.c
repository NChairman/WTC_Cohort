/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:41:32 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:33:50 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flag_a(char *s)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_just_ls(s);
	while (str[i])
		ft_printf("%-12s\t", str[i++]);
	ft_printf("\n");
	ft_free(&str);
}

void	ft_flag_l(char *s)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_just_ls(s);
	while (str[i][0] == '.')
		i++;
	while (str[i])
		ft_flag_ll(str[i++]);
	ft_free(&str);
}

void	ft_flag_r(char *s)
{
	char	**str;
	int		i;

	str = ft_just_ls(s);
	i = 0;
	while (str[i])
		i++;
	i -= 1;
	while (str[i] && str[i][0] != '.')
		ft_printf("%-12s\t", str[i--]);
	ft_printf("\n");
	ft_free(&str);
}
