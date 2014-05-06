/*
** exec.c for  in /home/charvo_a/42/execution
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May  5 15:28:59 2014 Nicolas Charvoz
** Last update Tue May  6 16:16:38 2014 Nicolas Charvoz
*/

#include "exec.h"

int	size_of_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int	exec_simple(char **cmd, char **path, char **env)
{
  int	i;
  int	status;
  pid_t	pid;
  char	*pass;

   /* if (check_builtin(mini) == 0) */
  /*   return(0); */
  i = -1;
  if ((pid = fork()) == -1)
    exit(-1);
  else if (pid == 0)
    {
      while (path[++i])
        {
	  pass = strcat(path[i], cmd[0]);
	  if (execve(pass, cmd, env) != -1)
            return(0);
        }
      printf("%s: Command not found\n", cmd[0]);
      exit(0);
    }
  else
    wait(&status);
  return (0);
}

void	send(char **tab, char **path, char **env)
{
  int	i;
  int	size;
  t_cmd	*cmd;

  cmd = malloc(sizeof(*cmd));
  i = 0;
  size = size_of_tab(tab);
  while (tab[i])
    {
      if (size == 1)
	{
	  parser2(tab[0], cmd);
	  exec_simple(cmd->args, path, env);
	}
      else
	{
	  printf("command too long\n");
	}
      i++;
    }
}
