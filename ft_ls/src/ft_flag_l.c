/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:16:16 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:34:20 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_one_type(mode_t val)
{
	char	c;

	c = '-';
	if (!val)
		return (c);
	if (S_ISBLK(val))
		c = 'b';
	else if (S_ISCHR(val))
		c = 'c';
	else if (S_ISDIR(val))
		c = 'd';
	else if (S_ISFIFO(val))
		c = 'p';
	else if (S_ISLNK(val))
		c = 'l';
	else if (S_ISSOCK(val))
		c = 's';
	return (c);
}

void	ft_rest_type(mode_t val, char **s)
{
	char	*file_t;

	file_t = *s;
	if (val)
	{
		if (val & S_IRUSR)
			file_t[1] = 'r';
		if (val & S_IWUSR)
			file_t[2] = 'w';
		if (val & S_IXUSR)
			file_t[3] = 'x';
		if (val & S_IRGRP)
			file_t[4] = 'r';
		if (val & S_IWGRP)
			file_t[5] = 'w';
		if (val & S_IXGRP)
			file_t[6] = 'x';
		if (val & S_IROTH)
			file_t[7] = 'r';
		if (val & S_IWOTH)
			file_t[8] = 'w';
		if (val & S_IXOTH)
			file_t[9] = 'x';
	}
}

char	*ft_file_type(struct stat fs)
{
	char	*file_t;
	mode_t	val;

	file_t = ft_strdup("----------");
	val = (fs.st_mode & S_IFMT);
	file_t[0] = ft_one_type(val);
	val = (fs.st_mode & ~S_IFMT);
	ft_rest_type(val, &file_t);
	return (file_t);
}

void	ft_user_group(struct stat fs)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(fs.st_uid);
	grp = getgrgid(fs.st_gid);
	ft_printf("\t%s", pwd->pw_name);
	ft_printf(" %s ", grp->gr_name);
}

void	ft_flag_ll(char *s)
{
	struct stat		fs;
	char			*file_t;
	char			buff[20];
	struct tm		*t_info;

	if (stat(s, &fs) == 0)
	{
		file_t = ft_file_type(fs);
		ft_printf("%s ", file_t);
		ft_printf("%ld", (long)fs.st_nlink);
		ft_user_group(fs);
		t_info = localtime(&(fs.st_mtime));
		strftime(buff, 20, "%b %d %H:%M", t_info);
		ft_printf(" %-7lld  %s %s\n", (long long)fs.st_size, buff, s);
		free(file_t);
	}
}
