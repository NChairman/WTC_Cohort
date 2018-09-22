/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:05:59 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:34:32 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static time_t	get_mt(char *path)
{
	struct stat	attr;

	if (stat(path, &attr) == 0)
		return (attr.st_mtime);
	return (0);
}

void			ft_sort_print(char **s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[j])
		{
			if (get_mt(s[j]) < get_mt(s[i]))
			{
				tmp = s[j];
				s[j] = s[i];
				s[i] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (s[i])
		ft_printf("%-12s\t", s[i++]);
	ft_printf("\n");
}

void			ft_flag_t(char *s)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_just_ls(s);
	while (str[i][0] == '.')
		i++;
	ft_sort_print(str + i);
	ft_free(&str);
}
