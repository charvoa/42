/*
** check_builtins.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Mon May 12 12:59:09 2014 louis audibert
** Last update Thu May 22 16:15:39 2014 Nicolas Charvoz
*/

#include "builtins.h"

int	find_cmd(char *cmd)
{
  char	**find;
  int	i;

  i = 0;
  find = malloc(5 * sizeof(char*));
  find[0] = "cd";
  find[1] = "env";
  find[2] = "echo";
  find[3] = "history";
  find[4] = NULL;
  while (find[i] != NULL)
    {
      if (strcmp(cmd, find[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	fill_builtins(int (**builtins)(t_42sh *shell, char **args, t_dlist *env))
{
  builtins[0] = &my_cd;
  builtins[1] = &my_env;
  builtins[2] = &my_echo;
  builtins[3] = &my_history;
}

int     check_builtins(t_42sh *shell, char **args, t_dlist *env)
{
  int   (*builtins[4])(t_42sh *shell, char **args, t_dlist *env);
  int	i;

  fill_builtins(builtins);
  i = 0;
  while (i < 4)
    {
      if (find_cmd(args[0]) == i)
	{
	  builtins[i](shell, args, env);
	  return (1);
	}
      i++;
    }
  return (0);
}
