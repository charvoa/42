/*
** list.c for list in /home/garcia_t/rendu/42sh
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat Apr 19 16:12:18 2014 garcia antoine
** Last update Tue Apr 22 14:51:44 2014 garcia antoine
*/

#include <stdlib.h>
#include <stdio.h>
#include "listok.h"

t_token	*insert(t_token *token, int type, char *value)
{
  t_token	*tok;
  t_token	*tmp;

  tok = malloc(sizeof(t_token));
  tok->type = type;
  tok->value = value;
  tok->next = NULL;
  if (token == NULL)
    return (tok);
  else
    {
      tmp = token;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = tok;
      return (token);
    }
}

t_token	*free_my_tok(t_token *token)
{
  t_token	*tmp;
  t_token	*tok;

  tmp = token;
  while (tmp != NULL)
    {
      tok = tmp->next;
      free(tmp);
      tmp = tok;
    }
  return NULL;
}

int	show_token(t_token *token)
{
  t_token	*tok;

  if (token == NULL)
    exit(EXIT_FAILURE);
  tok = token;
  while (tok != NULL)
    {
      printf("value : %s type: %d\n", tok->value, tok->type);
      tok = tok->next;
    }
  return (0);
}
