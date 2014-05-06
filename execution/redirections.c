/*
** test.c for test in /home/garcia_t
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Tue May  6 13:36:11 2014 garcia antoine
** Last update Tue May  6 16:57:49 2014 garcia antoine
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
}

int	double_redir_right(char **av)
{
  int	pid;
  int	fd;
  int	status;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      fd = open (av[1], O_WRONLY | O_CREAT | O_APPEND, 0666); 
      dup2(fd, 1);
      close(fd);
      execlp("ls", "ls", NULL);
      exit(1);
    }
  else
    wait(&status);
}

int	redir_right(char **av, char **env)
{
  int	pid;
  int	fd;
  int	status;

  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      fd = creat(av[1], 0644);
      dup2(fd, 1);
      close(fd);
      execlp("ls", "ls",  NULL);
      exit(1);
    }
  else
    wait(&status);
}
