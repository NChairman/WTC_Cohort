/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:08:02 by nkngweny          #+#    #+#             */
/*   Updated: 2018/07/18 12:28:19 by fledwaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_isop(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int		ft_op(int a, int b, char c)
{
	if (c == '+' && (a + b) >= -2147483648 && (a + b) <= 2147483647)
		return (a + b);
	else if (c == '-' && (a - b) >= -2147483648 && (a - b) <= 2147483647)
		return (a - b);
	else if (c == '*' && (a * b) >= -2147483648 && (a * b) <= 2147483647)
		return (a * b);
	else if (c == '/' && b != 0)
		return (a / b);
	return (a % b);
}

int		main(int ac, char **av)
{
	int arr[100];
	int nbr_i = 0;
	int i = 0;
	
	if (ac == 2)
	{
		while (av[1][i])
		{
			if(ft_isop(av[1][i]) && (av[1][i+1] == ' ' || !av[1][i+1]))
			{
				nbr_i--;
				arr[nbr_i-1] = ft_op(arr[nbr_i-1], arr[nbr_i], av[1][i]);
			}
			else
				arr[nbr_i++] = atoi(av[1] + i);
			while(av[1][i] && av[1][i] != ' ')
				i++;
			if(av[1][i] == ' ')
				i++;
		}
		if(nbr_i == 1)
			printf("%d\n", arr[0]);
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
