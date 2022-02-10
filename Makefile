# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 00:29:43 by jbernard          #+#    #+#              #
#    Updated: 2022/02/09 12:36:08 by jbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
SRCS = push_swap.c \
	sort_stack.c \
	sort_stack_encore.c \
	radix_sort.c \
	indexing.c \
	moves.c	\
	validate_input.c \
	stack.c \
	arrays.c \
	error_message.c \
	tools.c \
	more_tools.c \
	ft_split.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
