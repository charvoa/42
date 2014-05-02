/*
** parser.h for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:43:54 2014 Nicolas Charvoz
** Last update Fri May  2 11:21:00 2014 Nicolas Charvoz
*/

#ifndef _PARSER_H_
# define _PARSER_H_

# include "../env/list.h"
# include "../env/listok.h"
# include "../env/42sh.h"
# include "../lexer/src/lexer.h"

/* PARSER.C */
char	*check_token(t_token**, t_lex*);

#endif
