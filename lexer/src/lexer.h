/*
** lexer.h for  in /home/charvo_a/Work/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat Apr  5 15:42:30 2014 Nicolas Charvoz
** Last update Mon Apr 21 15:52:05 2014 Nicolas Charvoz
*/

#ifndef _LEXER_H_
#define _LEXER_H_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef	enum	s_token
  {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_COMMA,
    TOKEN_RED_L,
    TOKEN_RED_R,
    TOKEN_DBL_L,
    TOKEN_DBL_R,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NONE,
    TOKEN_UNK,
    TOKEN_END
  }		e_token;

typedef	struct	s_char
{
  int	token;
  char	*cmd;
}		t_char;

/* USELESS.C */
void	lexer_test(char*);
/* CHECK1.C */
int	check_letter(char c);
int	red_r(char*, int);
int	red_l(char*, int);
int	comma_check(char*, int);
int	pipe_check(char*, int);
/*  CHECK2.C */
int	check_and(char*, int);
#endif
