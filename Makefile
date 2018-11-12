# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <smakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/11/12 15:44:38 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

CC		=	@gcc

CFLAGS	+=	-Wall -Werror -Wextra -g3

SRCS	=	ft_printf.c			\
			ft_aux.c			\
			check.c 			\
			check_2.c 			\
			analyse.c			\
			conversion_c.c 		\
			conversion_d0.c 	\
			conversion_d.c		\
			conversion_d2.c		\
			conversion_d3.c		\
			conversion_s.c		\
			conversion_bs.c		\
			conversion_p.c		\
			conversion_x.c		\
			conversion_x1.c		\
			conversion_0.c		\
			conversion_none.c	\
			ft_putchar_printf.c 

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
