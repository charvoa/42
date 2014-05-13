/*
** strtotab.c for  in /home/charvo_a/42/env
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May  5 15:20:22 2014 Nicolas Charvoz
** Last update Mon May  5 17:30:48 2014 Nicolas Charvoz
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	count_char(char *str)
{
  int	c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}

int	count_word(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ':' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

char	**strtotab(char *str)
{
  int	i;
  int	b;
  int	a;
  char	**tab;

  b = 0;
  i = 0;
  a = 0;
  tab = malloc(sizeof(char*) * ((count_word(str) + 1)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ':' || str[i] == '\n')
        {
          while (str[++i] == ':');
          a = a + 1;
          b = 0;
        }
      tab[a] = malloc(sizeof(char) * ((count_char(str + i) + 1)));
      while ((str[i] != ':')  && (str[i] != '\n') && (str[i] != '\0'))
        tab[a][b++] = str[i++];
      tab[a][b] = '\0';
      strcat(tab[a], "/");
    }
  tab[a + 1] = NULL;
  return (tab);
}
