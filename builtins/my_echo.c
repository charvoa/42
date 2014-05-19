/*
** my_echo.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  8 11:33:49 2014 louis audibert
** Last update Mon May 19 15:41:30 2014 louis audibert
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../env/42sh.h"
#include "../env/list.h"

void	echo_from_var_env(char *opt, t_dlist *env)
{
  char	*path;
  int	i;
  int	j;

  i = 1;
  j = 0;
  path = malloc(strlen(opt) * sizeof(char));
  memset(path, 0, strlen(opt));
  while (opt[i])
    {
      path[j] = opt[i];
      j++;
      i++;
    }
  path = get_env(path, env);
  my_putstr(path);
}

int	my_echo(t_42sh *shell, char **args, t_dlist *env)
{
  int	i;

  i = 1;
  while (args[i])
    {
      if (args[i][0] == '$')
	echo_from_var_env(args[i], env);
      else
	{
	  my_putstr(args[i]);
	  if (args[i + 1] != NULL)
	    my_putchar(' ');
	}
      i++;
    }
  printf("\n");
  return (0);
}
