# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 12:40:59 by nkngweny          #+#    #+#              #
#    Updated: 2018/09/20 12:41:03 by nkngweny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c \
		coloring.c \
		get_width.c \
		nfunction.c \
		precise.c \
		handle_unicodes.c \
		ncharacter.c \
		wstr_prec.c \
		color.c \
		other_src/allocations.c \
		other_src/convert_z.c \
		other_src/hexa_test.c \
		other_src/rev.c \
		other_src/test.c \
		other_src/apply_conver.c \
		other_src/flaggings.c \
		other_src/str_del.c \
		other_src/var_flags.c \
		other_src/b_test.c \
		other_src/ft_itoa_.c \
		other_src/octal_conver.c \
		other_src/int_test.c \
		other_src/str_init.c \
		other_src/various_checks.c \
		libft/ft_atoi.c \
		libft/ft_strcmp.c \
		libft/ft_strdup.c \
		libft/ft_strncpy.c \
		libft/ft_putstr.c \
		libft/ft_strcpy.c \
		libft/ft_strlen.c \
		libft/ft_strcat.c \
		libft/ft_strncat.c \
		libft/ft_strequ.c \
		libft/ft_strnequ.c \
		libft/ft_strjoin.c \
		libft/ft_strsplit.c \
		libft/ft_strstr.c \
		libft/ft_strnstr.c \
		libft/ft_strsub.c \
		libft/ft_strwdup.c

OB = 	ft_printf.o \
		coloring.o \
		get_width.o \
		nfunction.o \
		precise.o \
		handle_unicodes.o \
		ncharacter.o \
		wstr_prec.o \
		color.o \
		allocations.o \
		convert_z.o \
		hexa_test.o \
		rev.o \
		test.o \
		apply_conver.o \
		flaggings.o \
		str_del.o \
		var_flags.o \
		b_test.o \
		ft_itoa_.o \
		octal_conver.o \
		str_init.o \
		various_checks.o \
		ft_atoi.o \
		ft_strcmp.o \
		ft_strdup.o \
		ft_strncpy.o \
		int_test.o \
		ft_putstr.o \
		ft_strcpy.o \
		ft_strlen.o \
		ft_strcat.o \
		ft_strequ.o \
		ft_strjoin.o \
		ft_strncat.o \
		ft_strjoin.o \
		ft_strjoin.o \
		ft_strncat.o \
		ft_strnequ.o \
		ft_strnstr.o \
		ft_strsplit.o \
		ft_strstr.o \
		ft_strsub.o \
		ft_strwdup.o

FLAGS = -Werror -Wall -Wextra

$(NAME):
		gcc -c $(FLAGS) $(SRCS)
		ar rc $(NAME) $(OB)
		ranlib $(NAME)

all: 	$(NAME)

clean:
		rm -f $(OB)

fclean: clean
		rm -f $(NAME)

re: 	fclean all
