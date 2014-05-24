/*
** pipes.c for pipes in /home/heitzl_s/test_zone/42/pipe
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May 14 15:05:12 2014 heitzl_s
** Last update Sat May 24 12:40:22 2014 Nicolas Charvoz
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "pipe.h"

void	create_pipes(t_cmd *cmd, int i)
{
  int   fd[2];

  pipe(fd);
  cmd[i].fdout = fd[1];
  cmd[i + 1].fdin = fd[0];
}

int	check_pipe_cmd(t_cmd *cmd, t_42sh *shell)
{
  char	*path;

  if (access(cmd->args[0], X_OK) == - 1)
    {
      path = real_path(cmd, shell);
      if (path != NULL)
	return (0);
      else
	return (-1);
    }
  else
    return (0);
}
