# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 13:00:26 by nkngweny          #+#    #+#              #
#    Updated: 2018/09/20 12:50:58 by nkngweny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
NAME=ft_ls
FLAGS= -Wall -Wextra -Werror
OBJECTS= src/ft_app_flags.o src/ft_flag_l.o src/ft_flag_rr.o src/ft_flag_t.o \
		 src/ft_flags_two.o src/ft_ls.o\

all: $(NAME)

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) -I src/ $< -o $@

$(NAME): $(OBJECTS)
	$(MAKE) -C ft_printf/
	$(CC) $(OBJECTS) ft_printf/libftprintf.a -o $(NAME)

clean:
	$(MAKE) -C ft_printf/ clean
	-rm $(OBJECTS)

fclean: clean
	$(MAKE) -C ft_printf/ fclean
	-rm -v $(NAME)

re: fclean all
