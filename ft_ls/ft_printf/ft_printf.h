/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:42:43 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:42:46 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>
# include <inttypes.h>

int			ft_printf(const char *format, ...);
wchar_t		*first_test(const char format, va_list ap, int *count);
wchar_t		*test_for_int(const char format, va_list ap, int *count);
wchar_t		*test_for_hex(const char format, va_list ap, int *count);
wchar_t		*test_with_cmp(const char format, va_list ap, int *count);
wchar_t		*test_with_cmp1(const char format, va_list ap, int *count);
wchar_t		*test_with_cmp2(const char format, va_list ap, int *count);
wchar_t		*test_with_z(const char format, va_list ap, int *count);
char		*call_color(const char *format);
wchar_t		*ft_strdup_wchar_to_wchar(wchar_t *str);
void		ft_del_str(wchar_t **str, wchar_t **arg);
void		nfunction(va_list ap, wchar_t *str, wchar_t **arg);
void		ft_sort_ascii(char ***s);
int			handle_minus(char *flags, int *width);
int			handle_hash(char *flags);
int			handle_plus(char *flags);
int			handle_zeros(char *flags);
int			handle_sp(char *flags);
int			handle_width(const char *str, int *i, va_list ap);
wchar_t		*handle_mwidth(wchar_t **arg, int width, char letter);
wchar_t		*handle_prec(wchar_t **arg, int p, const char letter);
wchar_t		*handle_flags(wchar_t **arg, char *flags, char letter, int width);
wchar_t		*handle_zero(wchar_t **arg, int width,\
							char letter, int hashtag);
wchar_t		*con_hash(wchar_t **arg, char letter);
char		*handle_similar(const char *format, int *i,\
			int zero, int hashtag);
int			precision(const char *str, int *i, va_list ap);
wchar_t		*handle_cflags(const char *format, va_list ap,\
			int *i, int *conv);
int			t_strlen(const char *format, int *i);
wchar_t		*changing_malloc(wchar_t **str, const char *format,\
			int *i, int count);
void		add_char(wchar_t **str, const char *format, int *i, int count);
wchar_t		*add_arg(wchar_t **str, wchar_t **arg, char a, int *count);
wchar_t		*to_str(char c);
wchar_t		*to_str_c(char c, int *count);
wchar_t		*ft_add_p(wchar_t *str);
wchar_t		*to_str_p(char c);
wchar_t		*ft_strncpy_wchar(wchar_t *dst, const wchar_t *src, size_t n);
wchar_t		*handle_unsigned(unsigned long long n, int base, int x);
wchar_t		*ft_itoa_signed_ll(long long n, int base);
wchar_t		*ft_strdup_wchar(const char *str);
int			ft_strlen_null(wchar_t *str, int count);
void		ft_strcpy_null(wchar_t **dst, wchar_t *src, int count);
char		*add_color(char **str, char *arg);
char		*changing_malloc_color(char **str, const char *format, int *i);
int			ft_putwstr(wchar_t **str, int count);
int			mask_unicode_2(unsigned int v);
int			mask_unicode_3(unsigned int v);
int			mask_unicode_4(unsigned int v);
void		reverse(wchar_t **str);
void		ft_chr_sys(char *s);
void		ft_str_sys(char *s);
wchar_t		*to_str_w(wchar_t c, int *count);
int			wstr_len(wchar_t *str);
int			wchar_len(wchar_t wc);
long		ft_watoi(const wchar_t *str);
void		initialize_three(int *a, int *b, int *c);
int			valid_letter(const char letter);
wchar_t		*ft_wcharnew(wchar_t *str, int i);
char		*ft_strdup_color(char *color, char **arg);

#endif
