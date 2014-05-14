/*
** pipes.c for 42sh in /home/girard_s/rendu/42/execution/pipes
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue May  6 14:01:38 2014 Nicolas Girardot
<<<<<<< HEAD
** Last update Wed May 14 14:19:23 2014 Nicolas Girardot
=======
** Last update Tue May 13 15:47:22 2014 heitzl_s
>>>>>>> 0356f97866e3acb62f856c59814eae75d5ac3ce8
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "pipe.h"

int		init_pipes(t_cmd *cmd_1, t_cmd *cmd_2, t_42sh *shell)
{
  pid_t		pid;
<<<<<<< HEAD
  pid_t		pid2;
  int		fd[2];
  int		status;

  pipe(fd);
  pid = fork();
  if (pid == 0)
    {
      printf("fils\n");
      close(fd[0]);
      dup2(fd[1], 1);
      exec_cmd(cmd_1, shell);
    }
  else
    {
      printf("père\n");
      wait(&status);
      pid2 = fork();
      close(fd[1]);
      if (pid2 == 0)
	{
	  printf("fils du père\n");
	  close(fd[1]);
	  dup2(fd[0], 0);
	  exec_cmd(cmd_2, shell);
	}
      else
	{
	  close(fd[0]);
	  printf("père du père\n");
	}
    }
  return (0);
=======
  int		fds[2];
  int		status;

  pid = fork();
  if (pipe(fds) == -1)
    return (-1);
  cmd_1->fdout = fds[1];
  cmd_2->fdin = fds[0];
  if (pid != 0)
    {
      waitpid(pid, NULL, NULL);
      dup2(fds[1], 1);
      close(fds[0]);
      execvp(cmd_1->args[0], cmd_1->args);
    }
  else
    {
      dup2(fds[0], 0);
      close(fds[1]);
      execvp(cmd_2->args[0], cmd_2->args);
    }
  //Dup les FD pour les sorties

  //exec dans le dup

  //redup pour généré sortie Stand

  //

  //  cmd_2->fdout = ;//
  return (0);
}

void	exec_pipe(t_cmd *cmds, int pos, t_42sh *shell)
{
  while (cmds[pos].token[0] == '|')
    {
      if (cmds[pos + 1].args[0] == NULL)
	{
	  //args = prompt()
	}
      init_pipes(&cmds[pos], &cmds[pos + 1], shell);
      pos++;
    }
>>>>>>> 0356f97866e3acb62f856c59814eae75d5ac3ce8
}
