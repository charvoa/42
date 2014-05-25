/*
** double_redir_left.c for 42sh in /home/heitzl_s/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 11:37:51 2014 heitzl_s
** Last update Sun May 25 10:55:09 2014 heitzl_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../parser/parser.h"
#include "../xlib/xlib.h"
#include "execution.h"

int	exec_double_left(t_cmd *cmd, int last, int first)
{
  char  *buffer;
  int	pos_cmd;

  pos_cmd = first - 1;
  buffer = xcalloc(4096, sizeof(char));
  while (first < last)
    {
      buffer = xcalloc(4096, sizeof(char));
      read(0, buffer, 4096);
      if (strncmp(buffer, cmd[first].args[0], strlen(cmd[first].args[0])) != 0)
	;
      else
	first++;
    }
  while (strncmp(buffer, cmd[last].args[0], strlen(cmd[last].args[0])) != 0)
    {
      buffer = xcalloc(4096, sizeof(char));
      read(0, buffer, 4096);
      if (strncmp(buffer, cmd[last].args[0], strlen(cmd[last].args[0])) != 0)
	write(cmd[pos_cmd].fdin, buffer, strlen(buffer));
    }
  close(cmd[pos_cmd].fdin);
  cmd[pos_cmd].fdin = xopenmode(cmd[last].args[0], O_RDONLY | O_APPEND,
			  S_IRWXU | S_IRWXG | S_IRWXO);
  return (0);
}

void	double_redir_left(t_cmd *cmd, t_cmd *cmd2, t_cmd *cmdg, int i)
{
  int	pos_cmd;

  (void)cmd2;
  if (cmd[i].type == 0)
    {
      pos_cmd = i;
      cmd->fdin = 1;
      while ((cmdg[i].token && strcmp(cmdg[i].token, "<<") == 0))
	i++;
      if (cmd[pos_cmd].type == 0)
	cmdg[pos_cmd].fdin = xopenmode(cmdg[i].args[0], O_RDWR | O_CREAT | O_APPEND,
				       S_IRWXU | S_IRWXG | S_IRWXO);
      cmdg[pos_cmd].fdout = 1;
      exec_double_left(cmd, i, pos_cmd + 1);
    }
}
