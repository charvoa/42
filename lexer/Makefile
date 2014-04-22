##
## Makefile for  in /home/charvo_a/42/lexer
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Mon Apr 21 15:01:55 2014 Nicolas Charvoz
## Last update Mon Apr 21 16:47:39 2014 Nicolas Charvoz
##

CC	= gcc

RM	= rm -f

CFLAGS  += -Wextra -Wall -Werror
CFLAGS  += -ansi -pedantic
CFLAGS  += -I.

LMY	= -L ./sources/ -lmy

NAME	= lexer

SRCS	=	./src/lexer.c \
		./src/check1.c \
		./src/check2.c \
		./src/useless.c \
		../env/*.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re