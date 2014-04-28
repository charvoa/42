/*
** epur_str.c for  in /home/charvo_a/42/lexer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:10:40 2014 Nicolas Charvoz
** Last update Mon Apr 28 10:21:55 2014 Nicolas Charvoz
*/

#include "lexer.h"

char	*epur_str(char *str)
{
  int	i;
  int	mabool;
  char	*str2;
  int	j;

  str2 = malloc(4096 * sizeof(char));
  memset(str2, 0, 4096);
  j = 0;
  i = 0;
  mabool = 0;
  if (str[0] == ' ' || str[0] == '\t')
    mabool = 1;
  while ((str[i] == ' ' || str[i] == '\t') && mabool == 1)
    i++;
  mabool = 1;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  mabool = 1;
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  if (str[i] == '\0')
	    mabool = 0;
	}
      if (mabool != 0)
	{
	  str2[j] = str[i];
	  j++;
	}
      i++;
    }
  printf("cmd => %s\n", str2);
  return (str2);
}
