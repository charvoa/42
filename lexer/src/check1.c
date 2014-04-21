/*
** check1.c for  in /home/charvo_a/42/lexer
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 14:55:27 2014 Nicolas Charvoz
** Last update Mon Apr 21 15:48:12 2014 Nicolas Charvoz
*/

#include "lexer.h"

int     check_letter(char c)
{
  int   i;
  char  *str;

  str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789 ";
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (0);
      i++;
    }
  return (-1);
}

int      red_l(char *str, int i)
{
  int   j;

  j = i;
  while (str[i] == '<')
    {
      if (str[j + 1] == '<')
        printf("DBL REDIRECTION GAUCHE :  %c[%d]%c[%d]\n", str[i], i, str[j + 1], j + 1);
      else
        printf("RED SIMPLE GAUCHE %c[%d]\n", str[i], i);
      i++;
    }
  return (i);
}

int      red_r(char *str, int i)
{
  int   j;

  j = i;
  while (str[i] == '>')
    {
      if (str[ j + 1] == '>')
        printf("DBL REDIRECTION DROITE :  %c[%d]%c[%d]\n", str[i], i, str[j + 1], j + 1);
      else
        printf("RED SIMPLE DROITE %c[%d]\n", str[i], i);
      i++;
    }
  return (i);
}

int      comma_check(char *str, int i)
{
  while (str[i] == ';')
    {
      printf("COMMA %c[%d]\n", str[i], i);
      i++;
    }
  return (i);
}

int      pipe_check(char *str, int i)
{
  int   j;

  j = i;
  while (str[i] == '|')
    {
      if (str[j + 1] == '|')
        printf("OR %c[%d]%c[%d]\n", str[i], i, str[j + 1], j + 1);
      else
        printf("PIPE %c[%d]\n", str[i], i);
      i++;
    }
  return (i);
}
