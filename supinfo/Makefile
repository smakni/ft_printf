CC 		= 	gcc 

OPT 	= 	-o 

NAME 	= 	cprintf 

CFLAGS 	= 	-w -Wall 

SRCS 	= 	cprintf.c \
			cprintf_affFunc.c \
			write_func.c \
			main.c 

OBJS 	= 	$(SRCS:.c=.o) 

RM 		= 	rm -rf 

all: 	build 

build:	$(OBJS) 
		$(CC) $(OPT) $(NAME) $(OBJS) $(CFLAGS) 

clear:	
		$(RM) $(OBJS) $(NAME)

re: 	clear all
