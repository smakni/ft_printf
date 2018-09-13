# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <smakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/09/13 13:58:22 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

CC		=	@gcc

CFLAGS	+=	-Wall -Werror -Wextra -g

SRCS	=	ft_printf.c		\
			check.c 		\
			analyse.c		\
			conversion_c.c 	\
			conversion_d.c	\
			conversion_d0.c \
			conversion_s.c	\
			conversion_p.c	\
			conversion_x.c	\
			conversion_0.c


OBJF	=	libft/*.o

OBJS	=	$(SRCS:.c=.o)

LM		=	@ar rc

RM		=	@rm -f

all :		$(NAME)

$(NAME)	:	$(OBJS)
			@make -C libft
			$(LM) $(NAME) $(OBJS) $(OBJF)
			@echo "[BUILD SUCCESS]"

clean	:	
			@make clean -C libft 
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME) libft/libft.a

re		:	fclean all

.PHONY : 	all