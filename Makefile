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

# At the very top of the file, after the header
MAKEFLAGS += --silent

NAME = push_swap
BONUS_NAME = checker
LIBFT = full_libft/libftfull.a
CC = gcc
CFLAGS += -Wall -Werror -Wextra -I $(INCS_DIR) -I$(LIBFT_INC)

#printing
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
CLEAR = \033[2K\r

# source and include directories
SRCS_DIR = src
SRCS_BONUS_DIR = src/checker_bonus/
INCS_DIR = include/
LIBFT_INC = full_libft/include/

# common sources
COMMON_SRC = /algo/swap_100.c \
	  /algo/swap_utils.c \
	  /algo/move.c \
	  /algo/sorts.c \
	  /algo/sort_three.c \
	  /data_func/get_stack.c \
	  /data_func/swap_func1.c \
	  /data_func/swap_func2.c \
	  /data_func/stack_utils.c \
	  /data_func/get_stack_utils.c \
	  /main_errors/errors.c \
	  /main_errors/main_utils.c

# push_swap
MAIN_SRC = /main_errors/main.c

# Checker specific sources
SRC_BONUS = checker_bonus.c \
			checker_utils_bonus.c

COMMON_SRCS = $(addprefix $(SRCS_DIR), $(COMMON_SRC))
MAIN_SRCS = $(addprefix $(SRCS_DIR), $(MAIN_SRC))
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS))

COMMON_OBJ = $(COMMON_SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C full_libft re

$(NAME): $(LIBFT) $(COMMON_OBJ) $(MAIN_OBJ)
	@printf "$(CLEAR)$(YELLOW)Creating $(NAME)..."
	@$(CC) -no-pie -o $(NAME) $(COMMON_OBJ) $(MAIN_OBJ) $(LIBFT) 2>/dev/null
	@printf "$(CLEAR)$(GREEN)✓ $(NAME) successfully created!\n"

bonus: $(LIBFT) $(COMMON_OBJ) $(OBJ_BONUS)
	@printf "$(CLEAR)$(YELLOW)Creating $(BONUS_NAME)..."
	@$(CC) -no-pie -o $(BONUS_NAME) $(COMMON_OBJ) $(OBJ_BONUS) $(LIBFT) 2>/dev/null
	@printf "$(CLEAR)$(GREEN)✓ $(BONUS_NAME) successfully created!\n"

clean:
	@printf "$(CLEAR)$(YELLOW)Cleaning object files..."
	@rm -f $(COMMON_OBJ) $(MAIN_OBJ) $(OBJ_BONUS)
	@printf "$(CLEAR)$(GREEN)✓ Object files cleaned!\n"

fclean: clean
	@$(MAKE) -C full_libft fclean
	@printf "$(CLEAR)$(YELLOW)Removing executables..."
	@rm -f $(NAME) $(BONUS_NAME)
	@printf "$(CLEAR)$(GREEN)✓ Executables removed!\n"
re: fclean all

.PHONY: all clean fclean re bonus
