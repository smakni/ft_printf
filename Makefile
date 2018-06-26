# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <smakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/06/26 21:04:20 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

CC		=	gcc

CFLAGS	+= -Wall -Werror -Wextra

SRCS	=	ft_printf.c		\
			check.c 		\
			analyse.c		\
			conversion.c 	\
			conversion_d.c	


LIBS	=	libft/*.c

OBJS	=	$(SRCS:.c=.o)

LM		=	ar rc

RM		=	rm -f

all :		$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			$(LM) $(NAME) $(OBJS) $(OBJF)
			@echo "[BUILD OK]"

clean	:	
			make clean -C libft 
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME) libft/libft.a

re		:	fclean all

.POHONY : 	all