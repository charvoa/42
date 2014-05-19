/*
** exec_simple_cmd.c for exec_simple_cmd in /home/garcia_t/42/execution
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri May  9 10:27:51 2014 garcia antoine
<<<<<<< Updated upstream
** Last update Mon May 19 10:19:43 2014 garcia antoine
=======
** Last update Tue May 13 10:26:01 2014 garcia antoine
>>>>>>> Stashed changes
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../parser/parser.h"

int	my_segfault(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	printf("my_segfault\n");
    }
  return (0);
}

int    check_cmd(t_cmd *cmd, t_42sh *shell)
{
  int   check;

  check = access(cmd->args[0], X_OK);
  if (check == - 1)
    return (0);
  if (check == 0)
    execve(cmd->args[0], cmd->args, shell->envtab);
  return (0);
}

int    exec_cmd(t_cmd *cmd, t_42sh *shell)
{
  int   i;
  char  *path;

  i = 0;
  check_cmd(cmd, shell);
  if (shell->path == NULL)
    {
      fprintf(stderr, "%s Command not found\n", cmd->args[0]);
      return (0);
    }
  while(shell->path[i])
    {
      path = strcat(shell->path[i], cmd->args[0]);
      execve(path, cmd->args, shell->envtab);
      i++;
    }
  return (-1);
}

int     exec_cmd_simple(t_cmd *cmd, t_42sh *shell)
{
  int   pid;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      if(exec_cmd(cmd, shell) == - 1)
	fprintf(stderr, "%s Command not found\n", cmd->args[0]);
      exit(1);
    }
  else
    wait(&cmd->status);
  return (0);
}
