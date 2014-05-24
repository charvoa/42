/*
** exec_new_redir.c for 42sh in /home/heitzl_s/test_zone/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 08:07:16 2014 heitzl_s
** Last update Sat May 24 11:01:59 2014 heitzl_s
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "execution.h"
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "../pipe/pipe.h"
#include "../xlib/xlib.h"
#include "../builtins/builtins.h"

int     exec_redir(t_cmd *cmd, int i) // GERE QUE LES DROITES POUR L'INSTANT
{
  char  *buffer;

  buffer = xcalloc(4096, sizeof(*buffer));
  if (cmd[i].type == 1 && cmd[i - 1].type == 1)
    {
      if ((strcmp(cmd[i - 1].token, ">") == 0)
	  || (strcmp(cmd[i - 1].token, ">>") == 0))
	{
	  read(cmd[i - 1].fdout, buffer, 4095);
	  write(cmd[i].fdin, buffer, (strlen(buffer) + 1));
	  close(cmd[i - 1].fdout);
	  close(cmd[i].fdin);
	  return (1);
	}
    }
  return (0);
}

int	start_execution(t_cmd *cmd, t_42sh *shell, int i)
{
  cmd[i].close_fd = which_one_to_close(cmd, i);
  printf("__________CMD_%d__________\n", i);
  printf("cmd[%d].type = %d\n", i , cmd[i].type);
  printf("cmd[%d].fdin = %d\n", i , cmd[i].fdin);
  printf("cmd[%d].fdout = %d\n", i , cmd[i].fdout);
  printf("cmd[%d].status = %d\n\n\n", i , cmd[i].status);
  if (cmd[i].type == 0)
    {
      if (check_and_close_father(cmd, shell, i) == -42)
	return (-42);
    }
  else
    exec_redir(cmd, i);
  waitpid(cmd[i].pid, &cmd[i].status, 0);
  return (0);
}
