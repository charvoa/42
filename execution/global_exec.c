/*
** global_exec.c for global_exec in /home/garcia_t/42/execution
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Thu May  8 16:21:37 2014 garcia antoine
** Last update Thu May  8 17:26:59 2014 garcia antoine
*/

#include <unistd.h>
#include "../parser/parser.h"

void	exec_cmd(t_cmd *cmd, t_42sh *shell)
{
  int	i;
  char	*path;

  i = 0;
  while(shell->path[i])
    {
      path = strcat(shell->path[i], cmd->args[0]);
      execve(path, cmd->args, shell->envtab);
      i++;
    }
}

void	check_cmd(t_cmd *cmd, t_42sh *shell)
{
  int	check;

  check = access(cmd->args[0], X_OK);
  if (check == 0)
    execve(cmd->args[0], cmd->args, shell->envtab);
}

int	exec_cmd_simple(t_cmd *cmd, t_42sh *shell)
{
  int	pid;
  int	status;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      check_cmd(cmd, shell);
      exec_cmd(cmd, shell);
      exit(1);
    }
  else
    wait(&status);
}

void	global_exec(t_cmd *cmd, t_42sh *shell, int tok)
{
  while (tok != 0)
    {
      if (cmd->token == NULL || strcmp(cmd->token, ";") == 0)
  	exec_cmd_simple(cmd, shell);
      tok--;
  }
}
