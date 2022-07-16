# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 16:21:22 by hayou             #+#    #+#              #
#    Updated: 2022/05/05 12:31:21 by hayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= do_op.c ft_op.c

OBJS	= $(SRCS:.c=.o)

GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= do-op

all : $(NAME)

%.o : %.c
	$(GCC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(GCC) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
