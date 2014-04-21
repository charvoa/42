/*
** list.c for list in /home/garcia_t/rendu/42sh
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat Apr 19 16:12:18 2014 garcia antoine
** Last update Sat Apr 19 16:57:21 2014 garcia antoine
*/

#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

int	insert(t_tokenlist *token, int  type, char *value)
{
  t_token	*tok;

  tok = malloc(sizeof(*tok));
  if (token == NULL || tok == NULL)
    return (0);
  tok->type = type;
  tok->value = value;
}

int	show_token(t_tokenlist *token)
{
  t_token	*tok;

  if (token == NULL)
    exit(EXIT_FAILURE);
  tok = token->first;
  while (tok != NULL)
    {
      printf("value : %s type: %d\n", tok->value, tok->type);
      tok = tok->next;
    }
  return (0);
}
