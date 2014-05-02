/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
** Last update Fri May  2 14:30:41 2014 Nicolas Charvoz
*/

#include "parser.h"

char		*check_token(t_token **token, t_lex *lexi)
{
  t_token       *tok;

  tok = *token;
  if ((tok->type != TOKEN_WORD || tok->type == TOKEN_UNK) && (tok))
    return (tok->value);
  //  if (tok->next)
  tok = tok->next;
  while (tok && tok->next)
    {
      if (tok->type == TOKEN_UNK)
  	{
  	  lexi->cmd[tok->pos - 1] = '\0';
  	  return (tok->value);
  	}
      if (tok->type != TOKEN_WORD && tok->next)
  	{
	  tok = tok->next;
  	  if (tok->type != TOKEN_WORD || tok->type == TOKEN_UNK)
  	    {
  	      lexi->cmd[tok->pos] = '\0';
  	      return (tok->value);
  	    }
  	}
      tok = tok->next;
    }
  return (NULL);
}
