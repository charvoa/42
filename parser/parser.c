/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
** Last update Mon Apr 28 15:35:46 2014 Nicolas Charvoz
*/

#include "parser.h"

int     check_token(t_token **token)
{
  t_token       *tok;

  if (token == NULL)
    exit(EXIT_FAILURE);
  tok = *token;
  if (tok->type != 0 && tok->type != NULL)
    {
      printf("bash : Syntax error near unexpected token `%s`\n", tok->value);
      return (-1);
    }
  if (tok->type != NULL)
    tok = tok->next;
  if (tok->type > 0 && tok->type != NULL)
    {
      tok = tok->next;
      if (tok->type != 0 && tok->type != NULL)
	{
	  printf("bash : Syntax error near unexpected token `%s`\n", tok->value);
	}
    }
  return (0);
}
