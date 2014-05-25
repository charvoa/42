/*
** check2.c for  in /home/charvo_a/42/lexer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 15:35:44 2014 Nicolas Charvoz
** Last update Sun May 25 13:11:35 2014 Nicolas Charvoz
*/

#include "lexer.h"

int	check_error_none(t_token **token)
{
  t_token	*tok;

  tok = *token;
  while (tok != NULL)
    {
      if (tok->type == TOKEN_WORD && tok->next)
	{
	  tok = tok->next;
	  if (tok->type == TOKEN_NONE)
	    tok = tok->next;
	}
      if (tok->type > TOKEN_WORD && tok->next)
	{
	  tok = tok->next;
	  if (tok->type == TOKEN_NONE && tok->next)
	    {
	      tok = tok->next;
	      if (tok->type > TOKEN_WORD)
		{
		  fprintf(stderr, "NULL is not a command");
		  return (-1);
		}
	    }
	}
      tok = tok->next;
    }
  return (0);
}

int	check_none(char *str, int i, t_token **token)
{
  if (str[i] == ' ')
    {
      while (str[i] == ' ')
	{
	  *token = insert(*token, TOKEN_NONE, " ", i);
	  i++;
	}
    }
  return (i);
}

int	check_and(char *str, int i, t_token **token)
{
  int	j;

  j = i;
  while (str[i] == '&')
    {
      if (str[j + 1] == '&')
	{
	  *token = insert(*token, TOKEN_AND, "&&", i);
	  i++;
	}
      else
	*token = insert(*token, TOKEN_UNK, "&", i);
      i++;
    }
  return (i);
}

int     check_letter2(char c)
{
  int   i;
  char  *str;

  str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789 -;|&<>";
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (0);
      i++;
    }
  return (-1);
}
