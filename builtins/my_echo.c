/*
** my_echo.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  8 11:33:49 2014 louis audibert
** Last update Tue May 13 15:16:30 2014 louis audibert
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"
#include "./list.h"

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
  printf("%s\n", path);
}

void	my_echo(char **opt, t_dlist *env)
{
  int	i;

  i = 0;
  while (opt[i])
    {
      if (opt[i][0] == '$')
	echo_from_var_env(opt[i], env);
      else
	printf("%s\n", opt[i]);
      i++;
    }
}
