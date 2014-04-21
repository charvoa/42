/*
** list.c for list in /home/garcia_t/rendu/42sh
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat Apr 19 16:12:18 2014 garcia antoine
** Last update Mon Apr 21 15:59:17 2014 garcia antoine
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
