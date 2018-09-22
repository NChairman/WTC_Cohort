# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 12:26:00 by nkngweny          #+#    #+#              #
#    Updated: 2018/08/29 18:33:42 by nkngweny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = clang
NAME=libftprintf.a
FLAGS= -Wall -Wextra -Werror
OBJECTS= ft_printf/ft_printf.o ft_printf/format_s.o ft_printf/format_x.o \
		 ft_printf/format_d.o ft_printf/ft_format.o ft_printf/ft_handle.o \
		 ft_printf/ft_validity.o ft_printf/ft_format_p.o ft_printf/ft_lmod.o \
		 ft_printf/ft_prec.o\

all: $(NAME)

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) -I libftprintf/ -I ft_printf/ $< -o $@

$(NAME): $(OBJECTS)
	$(MAKE) -C libftprintf/
	ar rc libftprintf.a $(OBJECTS) libftprintf/*.o 

clean:
	$(MAKE) -C libftprintf/ clean
	-rm $(OBJECTS)

fclean: clean
	$(MAKE) -C libftprintf/ fclean
	-rm -v $(NAME)

re: fclean all
