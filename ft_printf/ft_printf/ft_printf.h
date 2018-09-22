/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:24:16 by nkngweny          #+#    #+#             */
/*   Updated: 2018/08/29 18:32:09 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "../libftprintf/libft.h"
# define CON "%sSpdDioOuUxXcC"
# define PRE "0123456789"
# define L_MOD "hljz"
# define FLAGS "#+-0 "

typedef struct	s_format
{
	int		width;
	int		pre;
	int		space;
	int		hash;
	int		minus;
	int		plus;
	int		zero;
	int		valid;
	char	con_type;
	char	*length_mod;
	char	*form;
}				t_format;
char			*ft_work(char *str, va_list ap, int *nbr);
char			*ft_format(char **str, va_list ap, int *nbr);
char			*ft_format1(char **str, int *nbr);
void			ft_validity(char **str, t_format **format);
void			ft_flag(char **str, t_format **format);
void			ft_pre(char **str, t_format **format);
void			ft_prec(char **str, t_format **format);
void			ft_lmod(char **str, t_format **format);
void			ft_l_mod(char **str, t_format **format);
void			ft_con(char **str, t_format **format);
void			ft_init_format(t_format **format);
char			*ft_handle(t_format **format, va_list ap, int *nbr);
char			*ft_digit(t_format **format, va_list ap, int *nbr);
char			*ft_sstr(t_format **format, va_list ap, int *nbr);
char			*ft_wstr(t_format **formar, va_list ap, int *nbr);
char			*ft_digit(t_format **format, va_list ap, int *nbr);
char			*ft_sstr(t_format **format, va_list ap, int *nbr);
char			*ft_wstr(t_format **format, va_list ap, int *nbr);
char			*ft_xxhandle(t_format **format, va_list ap, int *nbr);
char			*ft_xhandle(t_format **format, va_list ap, int *nbr);
char			*ft_uhandle(t_format **format, va_list ap, int *nbr);
char			*ft_ohandle(t_format **format, va_list ap, int *nbr);
char			*ft_phandle(t_format **format, va_list ap, int *nbr);
char			*ft_chandle(t_format **format, va_list ap, int *nbr);
char			*ft_wchandle(t_format **format, va_list ap, int *nbr);
int				ft_wf_str(t_format **format, char **str);
int				ft_fw_digit(t_format **format, char **str);
int				ft_xformat(t_format **format, char **str
							, unsigned long long int x_tmp);
int				ft_oformat(t_format **format, char **str
							, unsigned long long int o_tmp);
int				ft_dformat(t_format **format, char **str, long long int d_tmp);
char			*ft_constr(wchar_t chr);
int				ft_printf(const char *str, ...);
#endif
