/*
** prepa.c for 42sh in /home/heitzl_s/42/execution
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Fri May 23 10:49:17 2014 heitzl_s
** Last update Sat May 24 12:40:01 2014 Nicolas Charvoz
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipe.h"
#include "../parser/parser.h"
#include "../env/42sh.h"

int	prepa_pipes(t_cmd *cmd)
{
  int   i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      while (cmd[i].token != NULL )
	{
          if ((strcmp(cmd[i].token, "|") == 0))
            create_pipes(cmd, i);
	  else if ((strcmp(cmd[i].token, "||") == 0))
	    cmd[i].fdout = 1;
	  else if ((strcmp(cmd[i].token, "&&") == 0))
	    cmd[i].fdout = 1;
          i++;
	}
    }
  if (cmd[i].type == 0)
    cmd[i].fdout = 1;
  return (0);
}
