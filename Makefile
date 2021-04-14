# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 20:18:18 by aapollo           #+#    #+#              #
#    Updated: 2021/01/28 02:11:52 by aapollo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I .

SRCS = ft_output_nbr.c ft_parser_utiles.c ft_printf.c ft_processing.c utiles.c utils2.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

$(NAME) :${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME} 

re: fclean all
