/*
** pipes.c for pipes in /home/heitzl_s/test_zone/42/pipe
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May 14 15:05:12 2014 heitzl_s
** Last update Thu May 22 12:10:02 2014 heitzl_s
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../parser/parser.h"
#include "../env/42sh.h"
#include "../pipe/pipe.h"

int		launch(t_cmd *cmd, t_42sh *shell, int i, int close_fd)
{
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      dup2(cmd[i].fdout, 1);
      dup2(cmd[i].fdin, 0);
      if (close_fd == 0 && cmd[i].fdout != 1)
	close(cmd[i + 1].fdin);
      else if (close_fd == 1)
	close(cmd[i - 1].fdout);
      else if (close_fd == 2)
	{
	  close(cmd[i - 1].fdout);
	  close(cmd[i + 1].fdin);
	}
      if (exec_cmd(&cmd[i], shell) == -1)
	printf("Command not found : %s\n", cmd->args[0]);
      exit(-1);
    }
  return (pid);
}

int		check_and_launch(t_cmd *cmd, t_42sh *shell, int i, int close_fd)
{
  if (check_builtins(shell, cmd->args, shell->env) == 1)
    ;
  else
    {
      cmd[i].pid = launch(cmd, shell, i, close_fd);
      if (close_fd == 1)
	close(cmd[i - 1].fdout);
      else if (close_fd == 2)
	{
	  close(cmd[i - 1].fdout);
	  close(cmd[i].fdin);
	}
    }
  return (0);
}

int		which_one_to_close(t_cmd *cmd, int i)
{
  if (cmd[i].fdin == 0)
    return (0);
  else if (cmd[i].fdout == 1)
    return (1);
  else
    return (2);
}

int	waiting_process(t_cmd *cmd)
{
  int	i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      waitpid(cmd[i].pid, &cmd[i].status, 0);
      i++;
    }
  waitpid(cmd[i].pid, &cmd[i].status, 0);
  return (0);
}

int             prepa_pipes(t_cmd *cmd)
{
  int   i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      cmd[i].fdin = 0;
      while (cmd[i].token != NULL )
        {
          if ((strcmp(cmd[i].token, "|") == 0))
            create_pipes(cmd, i);
          i++;
        }
    }
  cmd[i].fdout = 1;
  return (0);
}

int		execution(t_cmd *cmd, t_42sh *shell, int tok)
{
  int	i;
  int	close_fd;

  i = 0;
  while (tok != 0)
    {
      close_fd = which_one_to_close(cmd, i);
      if (cmd[i].type == 0)
	check_and_launch(cmd, shell, i, close_fd);
      tok--;
      i++;
    }
  waiting_process(cmd);
  return (0);
}

// catr | ls --> exec ls
// ls | catr --> command not found : ls
// Bouclinf quand deux commandes séparées par ';' et comportant pipes
// Surement changer la fonction waiting_process et l'adapter dans les cas de && et ||'
