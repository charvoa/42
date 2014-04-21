/*
** check2.c for  in /home/charvo_a/42/lexer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 15:35:44 2014 Nicolas Charvoz
** Last update Mon Apr 21 15:51:16 2014 Nicolas Charvoz
*/

#include "lexer.h"

int	check_and(char *str, int i)
{
  int	j;

  j = i;
  while (str[i] == '&')
    {
      if (str[j + 1] == '&')
	printf("AND SIMPLE %c[%d]\n", str[i], i);
      else
	printf("BACKGROUND AND :  %c[%d]%c[%d]\n", str[i], i, str[j + 1], j + 1);
      i++;
    }
  return (i);
}
