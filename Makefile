# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 13:34:24 by rkovinia          #+#    #+#              #
#    Updated: 2026/11/12 12:51:05 by rkovinia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR	= printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRCS		= main.c \
			  stack_utils.c \
			  number_handler.c \
			  error_handler.c \
			  parsing.c \
			  operations_base.c \
			  ops_utils.c \
			  ops_swap_push.c \
			  ops_rotate.c \
			  ops_reverse_rotate.c \
			  prepare.c \
			  sort_utils.c \
			  simple_sort.c \
			  medium_sort.c \
			  complex_sort.c \
			  small_sort.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
