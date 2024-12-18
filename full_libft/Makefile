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
	(cd ft_printf && ar x libftprintf.a && ar q ../$(NAME) *.o)
	(cd gnl && ar x libgnl.a && ar q ../$(NAME) *.o)

libft:
	$(MAKE) -C libft re

printf:
	$(MAKE) -C ft_printf re

gnl:
	$(MAKE) -C gnl re

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C gnl clean

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C gnl fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft printf gnl
