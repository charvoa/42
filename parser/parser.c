/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
** Last update Wed Apr 30 12:12:48 2014 Nicolas Charvoz
*/

#include "parser.h"

char		*check_token(t_token **token)
{
  t_token       *tok;

  if (token == NULL)
    exit(EXIT_FAILURE);
  tok = *token;
  if ((tok->type != TOKEN_WORD || tok->type == TOKEN_UNK) && (tok))
    return (tok->value);
  if (tok->next)
    tok = tok->next;
  if (tok->type == TOKEN_UNK)
    return (tok->value);
  if (tok->type != TOKEN_WORD && tok->next)
    {
      if (tok->next)
	tok = tok->next;
      if (tok->type != TOKEN_WORD || tok->type == TOKEN_UNK)
	return (tok->value);
    }
  return (NULL);
}
