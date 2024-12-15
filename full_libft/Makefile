# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 18:22:50 by mafioron          #+#    #+#            #
#    Updated: 2024/12/03 18:22:53 by mafioron         ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libftfull.a
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft printf gnl
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) ft_printf/libftprintf.a gnl/libgnl.a

libft:
	cd libft && make re

printf:
	cd ft_printf && make re

gnl:
	cd gnl && make re

clean:
	cd libft && make clean
	cd ft_printf && make clean
	cd gnl && make clean

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean
	cd gnl && make fclean
	rm -f $(NAME)

re: fclean alr

.PHONY: all clean fclean re libft printf gnl
