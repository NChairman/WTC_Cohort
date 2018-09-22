/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukhavham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:31:09 by ukhavham          #+#    #+#             */
/*   Updated: 2018/09/20 12:32:44 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_del_str(wchar_t **str, wchar_t **arg)
{
	free(*str);
	free(*arg);
	*arg = NULL;
	*str = NULL;
}

void	ft_chr_sys(char *s)
{
	system(s);
}

void	ft_str_sys(char *s)
{
	char	*s_tmp;

	if (s)
	{
		s_tmp = ft_strjoin("ls ", s);
		ft_chr_sys(s_tmp);
		free(s_tmp);
	}
}

void    ft_sort_ascii(char ***s)
{
	int		j;
	int		k;
	char	*tmp;
	char	**str;

	j = 0;
	str = *s;
	while (str[j])
	{
		k = 0;
		while (str[k])
		{
			if (ft_strcmp(str[j], str[k]) < 0)
			{
				tmp =  str[j];
				str[j] =  str[k];
				str[k] = tmp;
			}
			k++;
		}
		j++;
	}
}
