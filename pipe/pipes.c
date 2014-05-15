/*
** pipes.c for pipes in /home/heitzl_s/test_zone/42/pipe
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May 14 15:05:12 2014 heitzl_s
** Last update Thu May 15 11:06:59 2014 heitzl_s
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "pipe.h"

int             init_pipes(t_cmd *cmd_1, t_cmd *cmd_2, t_42sh *shell)
{
  pid_t         pid;
  pid_t         pid2;
  int           fd[2];
  int           status;

  pipe(fd);
  cmd_2->type = 1;
  test(cmd_1, 0, fd[1], shell, fd[0]);
  test(cmd_2, fd[0], 1, shell, fd[1]);
  close(fd[0]);
  close(fd[1]);
  wait(&status);
  wait(&status);
}

int	test(t_cmd *cmd, int fdi, int fdo, t_42sh *shell, int close_fd)
{
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      dup2(fdo, 1);
      dup2(fdi, 0);
      close(close_fd);
      exec_cmd(cmd, shell);
    }
  return (pid);
}
