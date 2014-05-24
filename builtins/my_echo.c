/*
** my_echo.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  8 11:33:49 2014 louis audibert
** Last update Sat May 24 04:47:42 2014 heitzl_s
*/

#include "builtins.h"
#include "../xlib/xlib.h"

int	echo_from_var_env(char *opt, t_dlist *env, t_cmd *cmd, int i)
{
  char	*path;
  int	x;
  int	j;

  x = 1;
  j = 0;
  path = xmalloc(strlen(opt) * sizeof(char));
  memset(path, 0, strlen(opt));
  while (opt[x])
    {
      path[j] = opt[x];
      j++;
      x++;
    }
  path = get_env(path, env);
  if (path == NULL)
    return (-1);
  write(cmd[i].fdout, path, (strlen(path)));
  return (0);
}

int	my_echo(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  int	x;

  (void)shell;
  x = 1;
  while (cmd[i].args[x])
    {
      if (cmd[i].args[x][0] == '$')
	echo_from_var_env(cmd[i].args[x], env, cmd, i);
      else
	{
	  write(cmd[i].fdout, cmd[i].args[x], (strlen(cmd[i].args[x])));
	  if (cmd[i].args[x + 1] != NULL)
	    write(cmd[i].fdout, " ", strlen(" "));
	}
      x++;
    }
  write(cmd[i].fdout, "\n", strlen("\n"));
  return (0);
}
