/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
** Last update Mon Apr 28 11:12:11 2014 Nicolas Charvoz
*/

#include "parser.h"

int     check_token(t_token *token)
{
  t_token       *tok;

  if (token == NULL)
    exit(EXIT_FAILURE);
  tok = token;
  if (tok->type != 0)
    {
      printf("bash : Syntax error near unexpected token `%s` , type : %d\n, %p", tok->value, tok->type, tok);
    }
  while (tok != NULL)
    {
      printf("value : %s type: %d position : %d adresse : %p\n", tok->value, tok->type, tok->pos, tok);
      tok = tok->next;
    }
  return (0);
}
