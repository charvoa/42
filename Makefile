##
## Makefile for  in /home/charvo_a/42/lexer
##
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
##
## Started on  Mon Apr 21 15:01:55 2014 Nicolas Charvoz
## Last update Sat May 24 00:05:44 2014 Nicolas Girardot
## Last update Fri May 23 10:57:46 2014 heitzl_s
## Last update Mon May  5 16:59:08 2014 garcia antoine
##

CC	= 	gcc

RM	= 	rm -f

TERM	=	./termcaps

LEXER	=	./lexer

USELESS	=	-g3

PARSER	=	./parser

XLIB	=	./xlib

PIPE	=	./pipe

EXEC	=	./execution

ENV	=	./env

PIPE	=	./pipe

BUILTINS=	./builtins

CFLAGS  += 	-Wextra -Wall -W -g3
CFLAGS	+=	-Wbad-function-cast -Wcast-align

LMY	=	-L $(ENV)/libsources/ -lmy

LIBTERM	=	-lncurses

NAME	=	42sh

SRCS	=	$(TERM)/termcaps.c			\
		$(LEXER)/lexer.c			\
		$(LEXER)/check1.c			\
		$(LEXER)/check2.c			\
		$(LEXER)/epur_str.c			\
		$(ENV)/dlist.c				\
		$(ENV)/init.c				\
		$(ENV)/list.c				\
		$(ENV)/main.c				\
		$(ENV)/prompt.c				\
		$(ENV)/start_shell.c			\
		$(ENV)/util_env.c			\
		$(ENV)/strtotab.c			\
		$(PARSER)/parser.c			\
		$(PARSER)/struct_fill.c			\
		$(PARSER)/pars.c			\
		$(EXEC)/global_exec.c			\
		$(EXEC)/exec_simple_cmd.c		\
		$(EXEC)/redirections.c			\
		$(EXEC)/signal.c			\
		$(EXEC)/close_functions.c		\
		$(EXEC)/execution.c			\
		$(PIPE)/pipes.c				\
		$(PIPE)/prepa_pipes.c			\
		$(XLIB)/xclose.c			\
		$(XLIB)/xdup2.c				\
		$(XLIB)/xmalloc.c			\
		$(XLIB)/xopen.c				\
		$(XLIB)/xpipe.c				\
		$(XLIB)/xread.c				\
		$(BUILTINS)/check_builtins.c		\
		$(BUILTINS)/my_cd.c			\
		$(BUILTINS)/my_echo.c			\
		$(BUILTINS)/my_history.c		\
		$(BUILTINS)/disp_history_from_line.c	\
		$(BUILTINS)/my_env.c			\
		$(BUILTINS)/modif_pwd.c			\
		$(BUILTINS)/modif_pwd2.c		\
		$(BUILTINS)/func_my_cd.c		\
		$(BUILTINS)/my_exit.c

OBJS	= 	$(SRCS:.c=.o)

CLEAR	=	$(shell clear)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LMY) $(LIBTERM) $(LDFLAGS)
		@(cat txt/42sh.txt)

clean:
		$(RM) $(OBJS) .hist42sh

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

charvo_a:
		@(cat txt/charvo_a.txt)

heitzl_s:
		@(cat txt/heitzl_s.txt)

girard_s:
		@(cat txt/girard_s.txt)

audibe_l:
		@(cat txt/audibe_l.txt)

garcia_t:
		@(cat txt/garcia_t.txt)

group:		charvo_a heitzl_s girard_s audibe_l garcia_t

.PHONY:		all clean fclean re charvo_a heitzl_s girard_s audibe_l garcia_t group

.PRECIOUS:	$(TERM)/termcaps.c		\
                $(LEXER)/lexer.c		\
                $(LEXER)/check1.c		\
		$(LEXER)/check2.c		\
		$(LEXER)/epur_str.c		\
                $(ENV)/dlist.c			\
                $(ENV)/init.c			\
		$(ENV)/list.c			\
                $(ENV)/main.c			\
		$(ENV)/prompt.c			\
                $(ENV)/start_shell.c		\
                $(ENV)/util_env.c		\
		$(ENV)/strtotab.c		\
                $(PARSER)/parser.c		\
                $(PARSER)/struct_fill.c		\
                $(PARSER)/pars.c		\
                $(EXEC)/global_exec.c		\
                $(EXEC)/exec_simple_cmd.c	\
                $(EXEC)/redirections.c		\
                $(PIPE)/pipes.c
