# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafioron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:31:44 by mafioron          #+#    #+#              #
#    Updated: 2024/11/14 20:05:25 by mafioron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = full_libft/libftfull.a
CC = gcc
CFLAGS += -Wall -Werror -Wextra -I $(INCS_DIR) -I$(LIBFT_INC) -g

# Add source and include directories
SRCS_DIR = src
INCS_DIR = include/
LIBFT_INC = full_libft/include/

SRC = /algo/swap_100.c /algo/swap_utils.c /data_func/get_stack.c /data_func/swap_func1.c /data_func/swap_func2.c /data_func/swap_utils.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C full_libft re

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(MAKE) -C full_libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C full_libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
