##
## Makefile for  in /home/charvo_a/42/lexer
## 
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
## 
## Started on  Mon Apr 21 15:01:55 2014 Nicolas Charvoz
## Last update Wed Apr 30 11:26:09 2014 Nicolas Charvoz
##

CC	= 	gcc

RM	= 	rm -f

LEXER	=	./lexer/src

USELESS	=	-g3

PARSER	=	./parser

ENV	=	./env

CFLAGS  += 	-Wextra -Wall -W
CFLAGS	+=	-Wbad-function-cast -Wcast-align

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
	 $(CC) $(OBJS) -o $(NAME) $(LMY) $(LDFLAGS) $(USELESS)
	 $(RM) $(OBJS)

clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

charvo_a:
	@(cat .txt/charvo_a.txt)

heitzl_s:
	@(cat .txt/heitzl_s.txt)

girard_s:
	@(cat .txt/girard_s.txt)

audibe_l:
	@(cat .txt/audibe_l.txt)

garcia_t:
	@(cat .txt/garcia_t.txt)
group:	charvo_a heitzl_s girard_s audibe_l garcia_t