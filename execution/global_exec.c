/*
** global_exec.c for global_exec in /home/garcia_t/42/execution

** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Thu May  8 16:21:37 2014 garcia antoine
** Last update Thu May 22 12:05:18 2014 heitzl_s

*/

#include <unistd.h>
#include "../parser/parser.h"
#include "execution.h"

void		create_pipes(t_cmd *cmd, int i)
{
  int	fd[2];

  pipe(fd);
  cmd[i].fdout = fd[1];
  cmd[i + 1].fdin = fd[0];
}

int	global_prepa(t_cmd *cmd)
{
  int	i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      cmd[0].fdin = 0;
      if (!strncmp(cmd[i].token, ">>", 2) || !strncmp(cmd[i].token, ">", 1)
	  || !strncmp(cmd[i].token, "<<", 2) || !strncmp(cmd[i].token, "<", 1))
	redirections(&cmd[i], &cmd[i + 1]);
      i++;
    }
}

void	semi_col(t_cmd *cmd, t_cmd *cmd2)
{
  cmd2->fdin = 0;
  cmd->fdout = 1;
}

int	prepa_semi_col(t_cmd *cmd)
{
  int	i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      if (!strncmp(cmd[i].token, ";", 1))
	semi_col(&cmd[i], &cmd[i + 1]);
      else if (cmd[i].token == NULL)
	cmd[i].fdout = 1;
      i++;
    }
}

int	print(t_cmd *cmd)
{
  int   i;

  i = 0;
  while (cmd[i].token != NULL)
    i++;
  return (0);
}

int	global_exec(t_cmd *cmd, t_42sh *shell, int tok)
{
  global_prepa(cmd);
  prepa_pipes(cmd);
  prepa_semi_col(cmd);
  print(cmd);
  execution(cmd, shell, tok);
}
