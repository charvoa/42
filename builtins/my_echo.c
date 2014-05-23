/*
** my_echo.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  8 11:33:49 2014 louis audibert
** Last update Sat May 24 00:46:02 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

int	echo_from_var_env(char *opt, t_dlist *env)
{
  char	*path;
  int	i;
  int	j;

  i = 1;
  j = 0;
  path = xmalloc(strlen(opt) * sizeof(char));
  memset(path, 0, strlen(opt));
  while (opt[i])
    {
      path[j] = opt[i];
      j++;
      i++;
    }
  path = get_env(path, env);
  if (path == NULL)
    return (-1);
  my_putstr(path);
  return (0);
}

int	my_echo(t_42sh *shell, t_cmd *cmd, t_dlist *env)
{
  int	i;

  (void)shell;
  i = 1;
  while (cmd->args[i])
    {
      if (cmd->args[i][0] == '$')
	echo_from_var_env(cmd->args[i], env);
      else
	{
	  my_putstr(cmd->args[i]);
	  if (cmd->args[i + 1] != NULL)
	    my_putchar(' ');
	}
      i++;
    }
  printf("\n");
  return (0);
}
