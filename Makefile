##
## Makefile for  in /home/charvo_a/42/lexer
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Mon Apr 21 15:01:55 2014 Nicolas Charvoz
## Last update Mon Apr 28 15:22:09 2014 Nicolas Charvoz
##

CC	= 	gcc

RM	= 	rm -f

LEXER	=	./lexer/src

PARSER	=	./parser

ENV	=	./env

CFLAGS  += 	-Wextra -Wall
CFLAGS  += 	-I.

LMY	=	-L $(ENV)/libsources/ -lmy

NAME	=	mysh

SRCS	=	$(LEXER)/lexer.c \
		$(LEXER)/check1.c \
		$(LEXER)/check2.c \
		$(LEXER)/epur_str.c \
		$(LEXER)/useless.c \
		$(ENV)/dlist.c \
		$(ENV)/init.c \
		$(ENV)/list.c \
		$(ENV)/main.c \
		$(ENV)/prompt.c \
		$(ENV)/start_shell.c \
		$(ENV)/util_env.c \
		$(PARSER)/parser.c

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
