/*
** set_env.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat May 24 04:48:21 2014 louis audibert
** Last update Sat May 24 05:03:41 2014 louis audibert
*/

#include "builtins.h"
#include "../execution/execution.h"
#include "../xlib/xlib.h"

int		set_env(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  t_node	*tmp;

  (void)shell;
  tmp = env->start;
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
      while (tmp)
	{
	  if (!strcmp(tmp->name, cmd[i].args[1]))
	    tmp->value = cmd[i].args[2];
	  tmp = tmp->next;
	}
    }
  return (0);
}
