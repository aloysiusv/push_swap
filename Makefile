# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 18:26:29 by lrandria          #+#    #+#              #
#    Updated: 2021/09/30 18:26:29 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS       =   checker
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	= 	$(BONUS_SRCS:.c=.o)
HDR			=	push_swap.h get_next_line/get_next_line.h
SRCS		=	main.c parse_args.c initialise_stacks.c \
				alohomora_5.c alohomora_500.c \
				swap_and_push.c rotations.c optimal_insertion.c\
				do_double_op.c do_double_rotate.c groups_and_flags.c return_pos.c  \
				utils.c utils_node.c utils_min_max.c
BONUS_SRCS	=	checker.c parse_args.c initialise_stacks.c \
				swap_and_push_checker.c rotations_checker.c return_pos.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				utils.c utils_node.c

all:		$(NAME) $(BONUS)

mandatory:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(BONUS)

$(BONUS):	$(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

debug:		$(OBJS)
			$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJS) -o $(NAME)

%.o:		%.c $(HDR)
			$(CC) $(CFLAGS) -c -o $@ $< 

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all bonus clean fclean re

# valgrind -s --leak-check=full --show-leak-kinds=all ./a.out 2 45 3