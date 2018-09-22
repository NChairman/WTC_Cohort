/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:31:12 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 14:01:58 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_directory(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void		ft_free(char ***str)
{
	char	**s;
	int		i;

	s = *str;
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void		ft_recursive_r(char *s)
{
	int		i;
	char	**str;
	char	*s_tmp;
	char	*s1_tmp;

	i = 0;
	if (is_directory(s))
	{
		ft_printf("%s:\n", s);
		str = ft_just_ls(s);
		ft_just(str);
		while (str[i][0] == '.')
			i++;
		s1_tmp = ft_strjoin(s, "/");
		while (str[i])
		{
			s_tmp = ft_strjoin(s1_tmp, str[i++]);
			ft_recursive_r(s_tmp);
			free(s_tmp);
		}
		free(s1_tmp);
	}
}

void		ft_flag_rr(char *s_path)
{
	char	**str;
	char	*s_tmp;
	int		i;
	char	*s1_tmp;

	str = ft_just_ls(s_path);
	ft_just(str);
	i = 0;
	while (str[i] && str[i][0] == '.')
		i++;
	s1_tmp = ft_strjoin(s_path, "/");
	while (str[i])
	{
		s_tmp = ft_strjoin(s1_tmp, str[i++]);
		ft_recursive_r(s_tmp);
		free(s_tmp);
	}
	free(s1_tmp);
	ft_free(&str);
}
