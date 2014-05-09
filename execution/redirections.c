/*
** test.c for test in /home/garcia_t
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue May  6 13:36:11 2014 garcia antoine
** Last update Fri May  9 13:29:13 2014 garcia antoine
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

int	double_redir_left(char *av)
{
  int	pid;
  int	status;
  char	*buffer;

  buffer = malloc(4096 * sizeof(char));
  pid = fork();
  if (pid == - 1)
    return (0);
  if (pid == 0)
    {
      
    }
  else
    wait(&status);
  return (0);
}

int	redir_left(char **av)
{
  int	pid;
  int	fd;
  int	status;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      fd = open(av[1], O_RDONLY);
      if (fd == -1)
	{
	  printf("file doesn't exist\n");
	  exit(0);
	}
      dup2(fd, 0);
      execlp("sort", "sort", NULL);
      exit(1);
    }
  else
    wait(&status);
  return (0);
}

int	double_redir_right(t_cmd *cmd, t_cmd *cmd2, t_42sh *shell)
{
  int	pid;
  int	fd;
  int	status;

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
    wait(&status);
  return (0);
}

int	redir_right(t_cmd *cmd, t_cmd *cmd2, t_42sh *shell)
{
  int	pid;
  int	fd;
  int	status;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      fd = creat(cmd2->args[0], 0644);
      dup2(fd, 1);
      close(fd);
      exec_cmd(cmd, shell);
      exit(1);
    }
  else
    wait(&status);
  return (0);
}
