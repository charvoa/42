/*
** check_list.c for 42sh in /home/heitzl_s/42
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 01:44:55 2014 heitzl_s
** Last update Sat May 24 01:45:32 2014 heitzl_s
*/

#include "alias.h"

t_token		**check_list(t_alias **alias, t_token **token)
{
  t_token	*tok;
  t_alias	*a;

  tok = *token;
  while (tok)
    {
      a = *alias;
      while (a)
	{
	  if (!(strncmp(a->ali[0], tok->value, strlen(a->ali[0]))))
	    {
	      tok->value = realloc(tok->value,
				   (strlen(tok->value) + strlen(a->ali[1]) + 2));
	      strcpy(tok->value, a->ali[1]);
	    }
	  a = a->next;
	}
      tok = tok->next;
    }
  return (token);
}
