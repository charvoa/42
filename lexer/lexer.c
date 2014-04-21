/*
** main.c for  in /home/charvo_a/Work/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Apr  4 13:56:53 2014 Nicolas Charvoz
** Last update Sat Apr 19 16:53:47 2014 Nicolas Charvoz
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

t_char	g_token[11][64] =
  {
    {TOKEN_WORD, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789-"},
    {TOKEN_END, "\n"},
    {TOKEN_AND, "&&"},
    {TOKEN_OR, "||"},
    {TOKEN_PIPE, "|"},
    {TOKEN_COMMA, ";"},
    {TOKEN_DBL_L, "<<"},
    {TOKEN_RED_L, "<"},
    {TOKEN_DBL_R, ">>"},
    {TOKEN_RED_R, ">"},
    {TOKEN_NONE, NULL},
  };

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

void	lexer_test(char *cmd)
{
  int	i = 0;
  int	pipe = 0;
  int	comma = 0;
  int	red_r = 0;
  int	red_l = 0;
  int	dbl_r = 0;
  int	dbl_l = 0;
  int	unk = 0;

  while (cmd[i])
    {
      if (cmd[i] == '|')
	pipe++;
      else if (cmd[i] == ';')
	comma++;
      else if (cmd[i] == '<' && cmd[i + 1] != '<')
	red_r++;
      else if (cmd[i] == '>' && cmd[i + 1] != '>')
	red_l++;
      else if (cmd[i] == '>' && cmd[i + 1] == '>')
	dbl_r++;
      else if (cmd[i] == '<' && cmd[i + 1] == '<')
	dbl_l++;
      else if ((check_letter(cmd[i]) == -1))
	unk++;
      i++;
    }
  printf("La commande suivante comporte %d pipe, %d point-virgule, %d redirection simple droite, %d redirection simple gauche, %d redirection double gauche, %d redirection double droite et %d séparateurs inconnus \n", pipe, comma, red_r, red_l, dbl_l, dbl_r, unk);
}

static int	word_check(char *str, int i)
{
  while ((check_letter(str[i]) != -1) && str[i])
    {
      printf("TOKEN_WORD => %c[%d]\n", str[i], i);
      i++;
     }
   return (i);
}

static int	comma_check(char *str, int i)
{
  while (str[i] == ';')
    {
      printf("COMMA %c[%d]\n", str[i], i);
      i++;
    }
  return (i);
}

static int	pipe_check(char *str, int i)
{
  int	j;

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

void	lex(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = word_check(str, i);
      i = comma_check(str, i);
      i = pipe_check(str, i);
    }
 printf("str => %s\n", str);
}

int		main(int ac, char **av)
{
  char	*buffer;
  int	ret;
  char	*cmd;

  cmd = malloc(4096 * sizeof(char));
  buffer = malloc(4096 * sizeof(char));
  ret = read(0, buffer, 4096);
  buffer[ret - 1] = '\0';
  lex(buffer);
  free(buffer);
  return (0);
}
