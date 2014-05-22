/*
** check2.c for  in /home/charvo_a/42/lexer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 15:35:44 2014 Nicolas Charvoz
** Last update Fri May  2 17:29:33 2014 Nicolas Charvoz
*/

#include "lexer.h"

# define CHECK_LETTER "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789 -;|&<>"

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

  str = CHECK_LETTER;
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (0);
      i++;
    }
  return (-1);
}
