/*
** exec_simple_cmd.c for exec_simple_cmd in /home/garcia_t/42/execution
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri May  9 10:27:51 2014 garcia antoine
** Last update Fri May  9 13:27:20 2014 garcia antoine
*/

#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include "../parser/parser.h"

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

void    exec_cmd(t_cmd *cmd, t_42sh *shell)
{
  int   i;
  char  *path;

  i = 0;
  check_cmd(cmd, shell);
  while(shell->path[i])
    {
      path = strcat(shell->path[i], cmd->args[0]);
      execve(path, cmd->args, shell->envtab);
      i++;
    }
}

int     exec_cmd_simple(t_cmd *cmd, t_42sh *shell)
{
  int   pid;
  int   status;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      exec_cmd(cmd, shell);
      exit(1);
    }
  else
    wait(&status);
  return (0);
}
