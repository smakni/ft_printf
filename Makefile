# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabri <sabri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/06/21 12:33:44 by sabri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

CC		=	gcc

CFLAGS	+= -Wall -Werror -Wextra

SRCS	=	ft_printf.c		\
			check.c 		\
			conversion.c 	\
			analyse.c		

LIBS	=	./libft/*c

OBJS	=	$(SRCS:.c=.o)

OBJF	=	$(LIBS:c=.o)

LM		=	ar rc

RM		=	rm -f

all :		$(NAME)

$(NAME)	:	$(OBJS) $(OBJF)
			$(LM) $(NAME) $(OBJS) $(OBJF)

.POHONY : 	all

clean	:	
			$(RM) $(OBJS) $(OBJF)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all