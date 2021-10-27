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
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
OBJS		=	$(SRCS:.c=.o)
HDR			=	push_swap.h
SRCS		=	main.c parse_args.c \
				swapping_pushing.c rotating.c sorting.c \
				utils.c utils_node.c utils_stack.c utils_sort.c \

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS)

bonus:		$(NAME)

%.o:		%.c $(HDR)
			$(CC) $(CFLAGS) -c -o $@ $< 

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re

# valgrind -s --leak-check=full --show-leak-kinds=all ./a.out 2 45 3