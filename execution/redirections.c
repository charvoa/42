/*
** test.c for test in /home/garcia_t
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Tue May  6 13:36:11 2014 garcia antoine
<<<<<<< Updated upstream
** Last update Thu May 22 11:46:48 2014 heitzl_s
=======
** Last update Fri May  9 18:32:33 2014 garcia antoine
>>>>>>> Stashed changes
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../parser/parser.h"
#include "execution.h"

static int	open_my_file(char *name)
{
  int	fd;

  if (access(name, F_OK) == -1 || access(name, R_OK) == -1)
    {
      if (access(name, F_OK) == -1)
	fprintf(stderr, "42sh: %s: no such file or directory.\n", name);
      else
	fprintf(stderr, "42sh: %s: don't have the permission to read the file.\n", name);
      return (-1);
    }
  fd = open(name, O_RDONLY);
  if (fd == - 1)
    printf("42sh : open error.\n");
  return (fd);
}

int	exec_double_left(t_cmd *cmd, t_cmd *cmd2)
{
  char	*buffer;
  char	**final;
  int	nb;
  static int i = 0;

  buffer = malloc(4096 * sizeof(char));
  final = malloc(4096 * sizeof(char *));
  nb = read(0, buffer, 4096);
  buffer[nb - 1] = '\0';
  if (!strcmp(buffer, "coucou"))
    {
      final[i] = strdup(buffer);
    }
  else
    {
      final[i] = strdup(buffer);
      i++;
      exec_double_left(cmd, cmd2);
    }
}

int	double_redir_left(t_cmd *cmd, t_cmd  *cmd2)
{
  int	pid;
  int	status;

  pid = fork();
  if (pid == - 1)
    return (0);
  if (pid == 0)
    {
      exec_double_left(cmd, cmd2);
    }
  else
    wait(&status);
  return (0);
}

int	redir_left(t_cmd *cmd, t_cmd *cmd2)
{
  cmd->fdout = 1;
  cmd->fdin = open(cmd2->args[0], O_RDONLY);
  cmd2->fdin = cmd->fdin;
  cmd2->fdout = cmd->fdin;
}

int	double_redir_right(t_cmd *cmd, t_cmd *cmd2)
{
  cmd->fdout = open(cmd2->args[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
  cmd2->fdin = cmd->fdout;
  cmd2->fdout = cmd->fdout;
}

int	redir_right(t_cmd *cmd, t_cmd *cmd2)
{
  char  *buffer;
  int   nb;
  int   fd;

  buffer = calloc(20, sizeof(*buffer));
  if (cmd->type == 0)
    {
      cmd->fdout = creat(cmd2->args[0], 0644);
      cmd2->fdin = cmd->fdout;
      cmd2->fdout = 0;
    }
  if (cmd->type == 1)
    {
      cmd2->fdout = 0;
      cmd2->fdin = creat(cmd2->args[0], 0644);
      fd = open(cmd->args[0] , O_RDONLY);
      while ((nb = read(fd, buffer, 19)) != 0)
        {
          write(cmd2->fdin, buffer, (strlen(buffer) +1));
          memset(buffer, 0, 20);
        }
    }
}

int	redirections(t_cmd *cmd, t_cmd *cmd2)
{
  cmd2->type = 1;
  if (!strncmp(cmd->token, ">>", 2))
    double_redir_right(cmd, cmd2);
  else if (!strncmp(cmd->token, ">", 1))
    redir_right(cmd, cmd2);
  else if (!strncmp(cmd->token, "<", 1))
    redir_left(cmd, cmd2);
}
