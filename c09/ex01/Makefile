# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hayou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 01:51:13 by hayou             #+#    #+#              #
#    Updated: 2022/05/03 19:51:52 by hayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= srcs
SRCS		= $(SRCS_DIR)/ft_putchar.c \
			  $(SRCS_DIR)/ft_swap.c \
			  $(SRCS_DIR)/ft_putstr.c \
			  $(SRCS_DIR)/ft_strlen.c \
			  $(SRCS_DIR)/ft_strcmp.c 

OBJS		= $(SRCS:.c=.o)

HEAD_DIR	= includes
HEAD		= $(HEAD_DIR)/ft.h

GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

all:	$(NAME)

$(NAME)	: $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS) $(HEADER)
	$(GCC) $(CFLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:  clean fclean re
