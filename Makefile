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

NAME		=	push_swap.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
HDR			=	push_swap.h
SRCS		=	main.c parse_args.c stack_creation.c \
				swapping_pushing.c rotating.c sorting.c \
				node_utils.c utils.c \

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(NAME)

test:		$(OBJS) main.o
			@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) main.o
			@./a.out

%.o:		%.c $(HDR)
			$(CC) $(CFLAGS) -c -o $@ $< 

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re