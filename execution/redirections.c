/*
** test.c for test in /home/garcia_t
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Tue May  6 13:36:11 2014 garcia antoine
** Last update Sat May 24 09:24:45 2014 heitzl_s
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

int	open_my_file(char *name)
{
  int	fd;

  if (access(name, F_OK) == -1 || access(name, R_OK) == -1)
    {
      if (access(name, F_OK) == -1)
	fprintf(stderr, "42sh: %s: no such file or directory.\n", name);
      else
	fprintf(stderr, "42sh: %s: Permission denied.\n", name);
      return (-1);
    }
  fd = xopen(name, O_RDONLY);
  if (fd == - 1)
    printf("42sh : open error.\n");
  return (fd);
}

void	redir_left(t_cmd *cmd, t_cmd *cmd2)
{
  if (cmd->type == 0)
    {
      cmd2->fdin = creat(cmd2->args[0], 0644);
      cmd->fdin = open_my_file(cmd2->args[0]);
      cmd2->fdout = 1;
    }
  else if (cmd->type == 1)
    {
      cmd2->fdin = creat(cmd2->args[0], 0644);
      cmd->fdout = open(cmd->args[0], O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    }
}

void	double_redir_right(t_cmd *cmd, t_cmd *cmd2)
{
  if (cmd->type == 0)
    {
      cmd->fdout = open(cmd2->args[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
      cmd2->fdin = cmd->fdout;
      cmd2->fdout = cmd->fdout;
    }
  else if (cmd->type == 1)
    {
      cmd2->fdin = creat(cmd2->args[0], 0644);
      cmd->fdout = open(cmd->args[0], O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    }
}

void	redir_right(t_cmd *cmd, t_cmd *cmd2)
{
  if (cmd->type == 0)
    {
      cmd->fdout = creat(cmd2->args[0], 0644);
      cmd2->fdin = cmd->fdout;
      cmd2->fdout = 0;
    }
  else if (cmd->type == 1)
    {
      cmd2->fdin = creat(cmd2->args[0], 0644);
      cmd->fdout = open(cmd->args[0], O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    }
}

void	redirections(t_cmd *cmd, t_cmd *cmd2)
{
  cmd2->type = 1;
  if (!strncmp(cmd->token, ">>", 2))
    double_redir_right(cmd, cmd2);
  else if (!strncmp(cmd->token, ">", 1))
    redir_right(cmd, cmd2);
  else if (!strncmp(cmd->token, "<", 1))
    redir_left(cmd, cmd2);
}
