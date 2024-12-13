# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:21:13 by egache            #+#    #+#              #
#    Updated: 2024/12/13 12:58:24 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD	=	ft_printf.h

NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_itoa.c\
			ft_uitoa.c\
			ft_printstr.c\
			ft_printhex.c\
			ft_printint.c\
			ft_printuint.c\
			ft_printptr.c\

OBJS	=	${SRCS:%.c=%.o}

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

${OBJS} :   %.o : %.c ${HEAD} Makefile
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS}
	${AR} ${NAME} ${OBJS}

clean	:
	rm -rf ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re	:	fclean all

.PHONY	:	all clean fclean re


