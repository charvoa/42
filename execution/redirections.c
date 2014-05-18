/*
** test.c for test in /home/garcia_t
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Tue May  6 13:36:11 2014 garcia antoine
<<<<<<< Updated upstream
** Last update Sun May 18 13:03:08 2014 garcia antoine
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
	fprintf(stderr, "42sh : %s : no such file or directory.\n", name);
      else
	fprintf(stderr, "42sh: %s: don't have the permission to read the file.\n", name);
      return (-1);
    }
  fd = open(name, O_RDONLY);
  if (fd == - 1)
    printf("42sh : open error.\n");
  return (fd);
}

int	double_redir_left(t_cmd *cmd, t_cmd  *cmd2)
{
  int	pid;
  int	status;
  char	*buffer;
  int	bool;
  char	*final;

  bool = 0;
  buffer = malloc(4096 * sizeof(char));
  pid = fork();
  if (pid == - 1)
    return (0);
  if (pid == 0)
    {
      while (bool == 0)
	{
	  read(0, buffer, 4096);
	  if (!strcmp(buffer, "coucou"))
	    bool = 1;
	}
    }
  else
    wait(&status);
  return (0);
} 

int	redir_left(t_cmd *cmd, t_cmd *cmd2, t_42sh *shell)
{
  int	pid;
  int	fd;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      if (fd = open_my_file(cmd2->args[0]) == -1)
	exit(-1);
      dup2(fd, 0);
      exec_cmd(cmd, shell);
      exit(1);
    }
  else
    wait(&cmd->status);
  return (0);
}

int	double_redir_right(t_cmd *cmd, t_cmd *cmd2, t_42sh *shell)
{
  int	pid;
  int	fd;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      fd = open(cmd2->args[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
      dup2(fd, 1);
      close(fd);
      exec_cmd(cmd, shell);
      exit(1);
    }
  else
    wait(&cmd->status);
  return (0);
}

int	redir_right(t_cmd *cmd, t_cmd *cmd2, t_42sh *shell)
{
  int	pid;
  int	fd;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      fd = creat(cmd2->args[0], 0644);
      if (fd == -1)
	exit(1);
      if(cmd2->args[0] == NULL)
	{
	  printf("erreur\n");
	  exit(1);
	}
      dup2(fd, 1);
      close(fd);
      exec_cmd(cmd, shell);
      exit(1);
    }
  else
    wait(&cmd->status);
  return (0);
}

int	redirections(t_cmd *cmd, t_cmd *cmd2, t_42sh *shell)
{
  cmd2->type = 1;
  if (!strcmp(cmd->token, ">>"))
    double_redir_right(cmd, cmd2, shell);
  else if (!strcmp(cmd->token, ">"))
    redir_right(cmd, cmd2, shell);
  else if (!strcmp(cmd->token, "<<"))
    double_redir_left(cmd, cmd2);
  else if (!strcmp(cmd->token, "<"))
    redir_left(cmd, cmd2, shell);
  return (0);
}
