/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:41:24 by nkngweny          #+#    #+#             */
/*   Updated: 2018/09/20 12:41:28 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		t_strlen1(const char *format, int *i)
{
	int		j;

	j = *i;
	while (format[j] && format[j] != '}')
		j++;
	return (j - *i);
}

char	*fix_color(char **arg, const char c)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy = malloc((ft_strlen(*arg) + 3) * sizeof(char));
	if (!cpy)
		exit(0);
	cpy[i++] = '{';
	while ((*arg)[j])
		cpy[i++] = (*arg)[j++];
	if (c == '}')
		cpy[i++] = '}';
	cpy[i] = '\0';
	free(*arg);
	return (cpy);
}

char	*color_init(const char *format, int *i, char **arg)
{
	if (ft_strcmp("teal", *arg) == 0)
		return (ft_strdup_color("\033[36m", arg));
	if (ft_strcmp("white", *arg) == 0)
		return (ft_strdup_color("\033[37m", arg));
	if (ft_strcmp("b", *arg) == 0)
		return (ft_strdup_color("\033[1m", arg));
	if (ft_strcmp("i", *arg) == 0)
		return (ft_strdup_color("\033[3m", arg));
	if (ft_strcmp("u", *arg) == 0)
		return (ft_strdup_color("\033[4m", arg));
	if (ft_strcmp("g", *arg) == 0)
		return (ft_strdup_color("\033[5m", arg));
	if (ft_strcmp("eoc", *arg) == 0)
		return (ft_strdup_color("\033[0m", arg));
	*arg = fix_color(arg, format[*i]);
	return (*arg);
}

char	*color_test(const char *format, int *i, char **arg)
{
	int		a;

	a = 0;
	*arg = malloc(1 + t_strlen1(format, i) * sizeof(char));
	if (!arg)
		exit(0);
	while (format[*i] != '}' && format[*i] && format[*i] != '{')
	{
		(*arg)[a++] = format[*i];
		++*i;
	}
	(*arg)[a] = '\0';
	if (ft_strcmp("black", *arg) == 0)
		return (ft_strdup_color("\033[30m", arg));
	if (ft_strcmp("red", *arg) == 0)
		return (ft_strdup_color("\033[31m", arg));
	if (ft_strcmp("green", *arg) == 0)
		return (ft_strdup_color("\033[32m", arg));
	if (ft_strcmp("brown", *arg) == 0)
		return (ft_strdup_color("\033[33m", arg));
	if (ft_strcmp("blue", *arg) == 0)
		return (ft_strdup_color("\033[34m", arg));
	if (ft_strcmp("purple", *arg) == 0)
		return (ft_strdup_color("\033[35m", arg));
	return (color_init(format, i, arg));
}

char	*call_color(const char *format)
{
	char	*str;
	char	*arg;
	int		i;

	i = 0;
	str = malloc(sizeof(char));
	if (!str)
		exit(0);
	str[0] = 0;
	str = changing_malloc_color(&str, format, &i);
	while (format[i])
	{
		str = changing_malloc_color(&str, format, &i);
		if (format[i] == '{')
		{
			++i;
			arg = color_test(format, &i, &arg);
			str = add_color(&str, arg);
			free(arg);
			if (format[i] == '}')
				++i;
		}
	}
	return (str);
}
