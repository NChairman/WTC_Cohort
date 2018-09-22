# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkngweny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 16:39:31 by nkngweny          #+#    #+#              #
#    Updated: 2018/08/29 18:21:00 by nkngweny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=libft.a
FLAGS=-Wall -Wextra -Werror -c
SRC = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o \
	  ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	  ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
	  ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
	  ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o \
	  ft_strnew.o ft_strdel.o ft_strclr.o ft_strmap.o ft_striter.o ft_striteri.o \
	  ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o \
	  ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putstr_fd.o \
	  ft_putendl_fd.o ft_putnbr_fd.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o \
	  ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
	  ft_itoa_base.o

all: $(NAME)

$(NAME): $(SRC)
	ar rc $(NAME) $(SRC)
	ranlib $(NAME)
$(SRC) : %.o : %.c
	clang -c $(FLAGS) $< -o $@

clean:
	rm -rf $(SRC)

fclean: clean
	rm -rf $(NAME)
re: fclean all
