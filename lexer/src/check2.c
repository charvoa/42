/*
** check2.c for  in /home/charvo_a/42/lexer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 15:35:44 2014 Nicolas Charvoz
** Last update Tue Apr 22 15:23:43 2014 garcia antoine
*/

#include "lexer.h"

int	check_and(char *str, int i, t_token **token)
{
  int	j;

  j = i;
  while (str[i] == '&')
    {
      if (str[j + 1] == '&')
	{
	  *token = insert(*token, TOKEN_AND, "&&");
	  i++;
	}
      else
	*token = insert(*token, TOKEN_UNK, "&");
      i++;
    }
  return (i);
}
