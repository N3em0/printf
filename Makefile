# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:21:13 by egache            #+#    #+#              #
#    Updated: 2024/12/01 18:50:12 by egache           ###   ########.fr        #
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

OBJ_DIR =   .objects/

OBJS	=	${SRCS:%.c=${OBJ_DIR}%.o}

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

${OBJS} :   ${OBJ_DIR}%.o : %.c ${HEAD}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_DIR} ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJ_DIR}  :
	mkdir -p ${OBJ_DIR}

clean	:
	rm -rf ${OBJ_DIR}

fclean	:	clean
	rm -f ${NAME}

re	:	fclean all

.PHONY	:	all clean fclean re


