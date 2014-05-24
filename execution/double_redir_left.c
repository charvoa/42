/*
** double_redir_left.c for 42sh in /home/heitzl_s/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 11:37:51 2014 heitzl_s
** Last update Sat May 24 15:34:42 2014 heitzl_s
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



int	exec_double_left(t_cmd *cmd, int i, int save)
{
  char  *buffer;

  while (save < i)
    {
      buffer = xcalloc(4096, sizeof(char));
      my_putstr(">");
      read(0, buffer, 4096);
      if (strncmp(buffer, cmd[save].args[0], strlen(cmd[save].args[0])) != 0)
	;
      else
	save++;
    }
  printf("MY save = %d\n", save);
  while (strncmp(buffer, cmd[save].args[0], strlen(cmd[save].args[0])) != 0)
    {
      buffer = xcalloc(4096, sizeof(char));
      my_putstr("-->");
      read(0, buffer, 4096);
      printf("buffer = %s\n", buffer);
      printf("cmd[%d].save = %s\n", save, cmd[save].args[0]);
      if (strncmp(buffer, cmd[save].args[0], strlen(cmd[save].args[0])) != 0)
	{
	  write(cmd[0].fdin, buffer, strlen(cmd[0].args[0])); // EN DUR
	  write(cmd[0].fdin, "\n", strlen("\n"));
	}
    }
  return (0);
}

void	double_redir_left(t_cmd *cmd, t_cmd *cmd2, t_cmd *cmdg, int i)
{
  int	save;
  int	save2;

  if (cmd[i].type == 0)
    {
      save = i;
      save2 = i;
      cmd->fdout = 1;
      cmd2->fdin = cmd->fdout;
      cmd2->fdout = cmd->fdout;
    }
  while ((cmdg[i].token && strcmp(cmdg[i].token, "<<") == 0))
    i++;
  printf("Avant qdqsdqsdqs | save = %d\n", save);
  if (cmd[save].type == 0)
    cmdg[save].fdin = xopenmode(cmdg[i].args[0], O_RDWR | O_CREAT | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
  while (save <= i)
    cmdg[save++].fdout = 1;
  printf("Avant fonction | save = %d\n", save2 + 1);
  printf("Avant fonction | i = %d\n", i);
  exec_double_left(cmd, i, save2 + 1);
}
