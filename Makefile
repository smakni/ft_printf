# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabri <sabri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/07/10 13:19:44 by sabri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

CC		=	gcc

CFLAGS	+= -Wall -Werror -Wextra

SRCS	=	ft_printf.c		\
			check.c 		\
			analyse.c		\
			conversion_c.c 	\
			conversion_d.c	\
			conversion_s.c	\
			conversion_p.c	\
			conversion_x.c


OBJF	=	libft/*.o

OBJS	=	$(SRCS:.c=.o)

LM		=	ar rc

RM		=	rm -f

all :		$(NAME)

$(NAME)	:	$(OBJS)
			@make -C libft
			$(LM) $(NAME) $(OBJS) $(OBJF)
			@clear
			@echo "[BUILD SUCCESS]"
			@sleep 1,5
			@clear

clean	:	
			@make clean -C libft 
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME) libft/libft.a

re		:	fclean all

.PHONY : 	all