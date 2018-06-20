# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabri <sabri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/06/20 20:41:39 by sabri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

CC		=	gcc

CFLAGS	+= -Wall -Werror -Wextra

SRCS	=	check.c 		\
			conversion.c 	\
			ft_printf.c		\

OBJS	=	$(SRCS:.c=.o)

LM		=	ar rc

RM		=	rm -f

all :		$(NAME)

$(NAME)	:	$(OBJS)
			$(LM) $(NAME) $(OBJS) libft/libft.a

.PHONY 	: 	$(NAME)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
