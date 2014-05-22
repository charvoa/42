/*
** close_functions.c for 42sh in /home/heitzl_s/test_zone/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May 22 13:54:57 2014 heitzl_s
** Last update Thu May 22 13:56:13 2014 heitzl_s
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "../pipe/pipe.h"

int             check_and_close_son(t_cmd *cmd, t_42sh *shell, int i, int close_fd)
{
  if (close_fd == 0 && cmd[i].fdout != 1)
    close(cmd[i + 1].fdin);
  else if (close_fd == 1)
    close(cmd[i - 1].fdout);
  else if (close_fd == 2)
    {
      close(cmd[i - 1].fdout);
      close(cmd[i + 1].fdin);
    }
  return (0);
}

int             check_and_close_father(t_cmd *cmd, t_42sh *shell, int i, int close_fd)
{
  if (check_builtins(shell, cmd->args, shell->env) == 1)
    ;
  else
    {
      cmd[i].pid = launch(cmd, shell, i, close_fd);
      if (close_fd == 1)
        close(cmd[i - 1].fdout);
      else if (close_fd == 2)
        {
          close(cmd[i - 1].fdout);
          close(cmd[i].fdin);
        }
    }
  return (0);
}

int             which_one_to_close(t_cmd *cmd, int i)
{
  if (cmd[i].fdin == 0)
    return (0);
  else if (cmd[i].fdout == 1)
    return (1);
  else
    return (2);
}
