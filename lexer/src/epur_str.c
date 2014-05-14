/*
** epur_str.c for  in /home/charvo_a/42/lexer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:10:40 2014 Nicolas Charvoz
** Last update Wed May  7 11:05:27 2014 Nicolas Charvoz
*/

#include "lexer.h"

char	*epur_str2(char *str, char *str2, int mabool, int i)
{
  int	j;

  j = 0;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  mabool = 1;
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  if (str[i] == '\0')
	    mabool = 0;
	  str2[j] = ' ';
	  j++;
	}
      if (mabool != 0)
	{
	  str2[j] = str[i];
	  j++;
	}
      i++;
    }
  str2[j] = '\0';
  return (str2);
}

char	*epur_str(char *str)
{
  int	i;
  int	mabool;
  char	*str2;

  str2 = malloc((strlen(str) + 1) * sizeof(char));
  memset(str2, 0, (strlen(str) + 1));
  i = 0;
  mabool = 0;
  if (str[0] == ' ' || str[0] == '\t')
    mabool = 1;
  while ((str[i] == ' ' || str[i] == '\t') && mabool == 1)
    i++;
  mabool = 1;
  str2 = epur_str2(str, str2, mabool, i);
  return (str2);
}
