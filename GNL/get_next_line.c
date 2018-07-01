/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:03:05 by nkngweny          #+#    #+#             */
/*   Updated: 2018/06/16 14:10:42 by nkngweny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_store(char **line, char **str)
{
	char	*temp;
	char	*temp1;
	char	*c;

	temp = *str;
	temp1 = *str;
	c = ft_strchr(temp, '\n');
	*line = ft_strsub(temp, 0, c - temp);
	while(*temp)
		temp++;
	c++;
	*str  = ft_strsub(temp1, c - temp1, temp - c);
	free(temp1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*c;
	char		*str;
	char		*temp;
	int			k;

	str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if(line && fd >= 0 && read(fd, str, 0) >= 0)
	{
		if (c != NULL && ft_strchr(c, '\n'))
		return (ft_store(line, &c));
		while ((k = read(fd, str, BUFF_SIZE)) > 0)
		{
			if(c == NULL)
				c = ft_strdup("");
			temp = c;
			c = ft_strjoin(temp, str);
			free(str);
			free(temp);
			if (ft_strchr(c, '\n') != NULL)
				return (ft_store(line, &c));
		}
		if (k == 0)
		{
			if(ft_strlen(c) > 0)
			{
				*line = c;
				c = NULL;
				return (1);
			}
			return (0);
		}
		return (-1);
	}
	return (-1);
}
