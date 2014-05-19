/*
** pipes.c for pipes in /home/heitzl_s/test_zone/42/pipe
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May 14 15:05:12 2014 heitzl_s
** Last update Mon May 19 10:41:59 2014 Nicolas Girardot
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "pipe.h"

int    check_pipe_cmd(t_cmd *cmd, t_42sh *shell)
{
  int   i;
  char  *path;

  i = 0;
  if (access(cmd->args[0], X_OK) == - 1)
    {
      while(shell->path[i])
	{
	  path = strcat(shell->path[i], cmd->args[0]);
	  if (access(path, X_OK) == 0)
	    return (0);
	  i++;
	}
      return (-1);
    }
  else
    {
      return (0);
    }
}

int	exec_first_cmd(t_cmd *cmd, int *fd, t_42sh *shell)
{
  int	close_fd;
  pid_t	pid;

  close_fd = fd[0];
  pid = fork();
  if (pid == 0)
    {
      if (check_pipe_cmd(cmd, shell) == -1)
	{
	  printf("Command not found : %s\n", cmd->args[0]);
	  exit (-1);
	}
      dup2(fd[1], 1);
      dup2(0, 0);
      close(close_fd);
      exec_cmd(cmd, shell);
      exit (-1);
    }
  return (pid);
}

int	exec_second_cmd(t_cmd *cmd, int *fd, t_42sh *shell)
{
  int	close_fd;
  pid_t	pid;

  close_fd = fd[1];
  pid = fork();
  if (pid == 0)
    {
      if (check_pipe_cmd(cmd, shell) == -1)
	{
	  printf("Command not found : %s\n", cmd->args[0]);
	  exit (-1);
	}
      dup2(1, 1);
      dup2(fd[0], 0);
      close(close_fd);
      if (exec_cmd(cmd, shell) == -1)
	printf("Command not found : %s\n", cmd->args[0]);
      exit (-1);
    }
  return (pid);
}

int		init_pipes(t_cmd *cmd_1, t_cmd *cmd_2, t_42sh *shell, int i)
{
  pid_t		pid_1;
  pid_t		pid_2;
  int           fd[2];
  int           status;

  pid_2 = -1;
  pipe(fd);
  cmd_2->type = 1;
  pid_1 = exec_first_cmd(cmd_1, fd, shell);
  if (pid_1 >= 0)
    pid_2 = exec_second_cmd(cmd_2, fd, shell);
  close(fd[0]);
  close(fd[1]);
  waitpid(pid_1, &status, 0);
  waitpid(pid_2, &status, 0);
  return (0);
}
