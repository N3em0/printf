# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:21:13 by egache            #+#    #+#              #
#    Updated: 2024/11/27 21:37:19 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\

OBJ_D	= .objects/

OBJS	=	$(SRCS:%.c=(OBJ_D)%.o)

HEAD	=	ft_printf.h

NAME	=	libftprintf.a

CC	=	cc

AR			=	ar -rc

CFLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(OBJS)		:	$(OBJ_DIR)%.o : %.c $(HEAD) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME)		:	$(OBJS) $(OBJ_D) Makefile
				$(AR) $(NAME) $(OBJS)

$(OBJ_D)	:
	@mkdir -p $(OBJ_D)

clean	:
	rm -rf $(OBJ_D)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re


