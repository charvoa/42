##
## Makefile for  in /home/charvo_a/42/lexer
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Mon Apr 21 15:01:55 2014 Nicolas Charvoz
## Last update Tue Apr 22 14:18:19 2014 Nicolas Charvoz
##

CC	= 	gcc

RM	= 	rm -f

CFLAGS  += 	-Wextra -Wall
CFLAGS  += 	-pedantic
CFLAGS  += 	-I.

LMY	=	-L ../env/libsources/ -lmy

NAME	=	lexer

SRCS	=	./src/lexer.c \
		./src/check1.c \
		./src/check2.c \
		./src/useless.c \
		../env/dlist.c \
		../env/init.c \
		../env/list.c \
		../env/main.c \
		../env/prompt.c \
		../env/start_shell.c \
		../env/util_env.c

OBJS	= 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LMY) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re