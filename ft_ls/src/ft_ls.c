/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:56:19 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 14:16:54 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_just_ls(char *str)
{
	char			*s;
	struct dirent	*sd;
	DIR				*dir;
	char			**s_tmp;
	char			*tmp;

	s = strdup("");
	dir = opendir(str);
	while ((sd = readdir(dir)))
	{
		tmp = s;
		s = ft_strjoin(tmp, sd->d_name);
		free(tmp);
		tmp = s;
		s = ft_strjoin(tmp, " ");
		free(tmp);
	}
	s_tmp = ft_strsplit(s, ' ');
	ft_sort_ascii(&s_tmp);
	free(s);
	closedir(dir);
	return (s_tmp);
}

void	ft_just(char **s)
{
	int		i;

	i = 0;
	while (s[i] && s[i][0] == '.')
		i++;
	while (s[i])
		ft_printf("%-12s\t", s[i++]);
	ft_printf("\n");
}

void	ft_adv_ls(char *s)
{
	char	**str;

	str = ft_just_ls(s);
	ft_just(str);
	ft_free(&str);
}

void	ft_app_flags(char *s_tmp, char *s)
{
	if (ft_strequ(s_tmp, "-a"))
		ft_flag_a(s);
	else if (ft_strequ(s_tmp, "-l"))
		ft_flag_l(s);
	else if (ft_strequ(s_tmp, "-t"))
		ft_flag_t(s);
	else if (ft_strequ(s_tmp, "-r"))
		ft_flag_r(s);
	else
		ft_flag_rr(s);
}

int		main(int ac, char **av)
{
	struct stat	fs;

	if (ac == 1 || (ac == 2 && ft_strequ(av[1], ".")))
		ft_adv_ls(".");
	else if (ac == 2 && (stat(av[1], &fs) == 0))
		ft_adv_ls(av[1]);
	else if (ac == 2 && ft_strstr(FLEG, av[1]))
		ft_app_flags(av[1], ".");
	else if ((ac == 2 && !ft_strequ(FLAG, av[1])) && (stat(av[1], &fs) < 1))
		ft_printf("The converstion is not suppoerted or file does not exist\n");
	else if (ac == 3 && ft_strstr(FLEG, av[1]) && (stat(av[2], &fs) == 0))
		ft_app_flags(av[1], av[2]);
	else
		ft_flags_two(ac, av);
	return (0);
}
