/*
** set_env.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat May 24 04:48:21 2014 louis audibert
** Last update Sat May 24 05:21:55 2014 louis audibert
*/

#include "builtins.h"
#include "../execution/execution.h"
#include "../xlib/xlib.h"

int		set_env_in_list(t_cmd *cmd, t_dlist *env, int i)
{
  t_node	*tmp;
  int	bool;

  bool = 0;
  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, cmd[i].args[1]))
	{
	  bool = 1;
	  tmp->value = cmd[i].args[2];
	}
      else
	bool = 0;
      tmp = tmp->next;
    }
  if ((bool = 0))
    put_in_list(env, cmd[i].args[1], cmd[i].args[2]);
  return (0);
}

int		set_env(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  (void)shell;
  if (cmd[i].args)
    {
      if (cmd[i].args[1] == NULL)
	{
	  fprintf(stderr, "Usage: set 'variable' 'value'\n");
	  return (-1);
	}
      else if (cmd[i].args[2] == NULL)
	{
	  fprintf(stderr, "Usage: set 'variable' 'value'\n");
	  return (-1);
	}
      set_env_in_list(cmd, env, i);
    }
  return (0);
}
