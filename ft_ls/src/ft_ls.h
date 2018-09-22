/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:41:30 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 14:14:44 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <unistd.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/time.h>
# include <glob.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <string.h>
# define FLAG "-R"
# define FLEG "-r-t-l-a"

void	ft_flag_a(char *s);
void	ft_flag_l(char *s);
void	ft_flag_r(char *s);
void	ft_flag_flags(char *s_tmp, char *s);
void	ft_adv_ls(char *s);
void	ft_just(char **s);
char	**ft_just_ls(char *str);
char	ft_one_type(mode_t val);
void	ft_rest_type(mode_t val, char **s);
char	*ft_file_type(struct stat fs);
void	ft_user_group(struct stat fs);
void	ft_flag_ll(char *s);
void	ft_recursive_r(char *s);
void	ft_flag_rr(char *s_path);
void	ft_sort_print(char **s);
void	ft_flag_t(char *s);
void	ft_flags_two(int ac, char **s);
void	ft_free(char ***s);
#endif
