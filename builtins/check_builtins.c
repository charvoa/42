/*
** check_builtins.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Mon May 12 12:59:09 2014 louis audibert
** Last update Sat May 24 01:46:13 2014 heitzl_s
*/

#include "builtins.h"
#include "../xlib/xlib.h"

int	find_cmd(char *cmd)
{
  char	**find;
  int	i;

  i = 0;
  find = xmalloc(6 * sizeof(char*));
  find[0] = "cd";
  find[1] = "env";
  find[2] = "echo";
  find[3] = "history";
  find[4] = "exit";
  find[5] = NULL;
  while (find[i] != NULL)
    {
      if (strcmp(cmd, find[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	fill_builtins(int (**builtins)(t_42sh *shell, t_cmd *cmd, t_dlist *env))
{
  builtins[0] = &my_cd;
  builtins[1] = &my_env;
  builtins[2] = &my_echo;
  builtins[3] = &my_history;
  builtins[4] = &my_exit;
}

int     check_builtins(t_42sh *shell, t_cmd *cmd, t_dlist *env)
{
  int   (*builtins[5])(t_42sh *shell, t_cmd *cmd, t_dlist *env);
  int	i;

  fill_builtins(builtins);
  i = 0;
  if (cmd->args)
    {
      while (i < 5)
	{
	  if ( find_cmd(cmd->args[0]) == i)
	    {
	      if (builtins[i](shell, cmd, env) == -42)
		return (-42);
	      return (1);
	    }
	  i++;
	}
    }
  return (0);
}
