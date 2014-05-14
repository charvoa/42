/*
** check_builtins.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Mon May 12 12:59:09 2014 louis audibert
** Last update Tue May 13 15:18:38 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"
#include "./list.h"

int	find_cmd(char *cmd)
{
  char	**find;
  int	i;

  i = 0;
  find = malloc(4 * sizeof(char*));
  find[0] = "cd";
  find[1] = "env";
  find[2] = "echo";
  find[3] = NULL;
  while (find[i] != NULL)
    {
      if (strcmp(cmd, find[i]) == 0)
	return (i);
      i++;
    }
  free_tab(find);
  return (0);
}

void	fill_builtins(int (**builtins)(char **opt, t_dlist *env))
{
  builtins[0] = &my_cd;
  builtins[1] = &my_env;
  builtins[2] = &my_echo;
}

int     check_builtin(char *cmd, char **opt, t_dlist *env)
{
  int   (*builtins[3])(char **opt, t_dlist *env);
  int	i;

  fill_builtins(builtins);
  i = 0;
  while (i <= 3)
    {
      if (find_cmd(cmd) == i)
	builtins[i](opt, env);
      i++;
    }  
  return (0);
}
