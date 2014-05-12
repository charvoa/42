/*
** pipes.c for 42sh in /home/girard_s/rendu/42/execution/pipes
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue May  6 14:01:38 2014 Nicolas Girardot
** Last update Mon May 12 13:33:36 2014 Nicolas Girardot
*/

#include <unistd.h>
#include "../parser/parser.h"
#include "../env/42sh.h"

int		init_pipes(t_cmd cmd_1, t_cmd cmd_2, t_42sh *shell)
{
  char		*path;
  pid_t		pid;
  int		fds[2];

  pid = fork();
  if (pipe(fds) == -1)
    return (-1);
  cmd_1.fdout = fds[1];
  cmd_2.fdin = fds[0];
  if (pid == 0)
    {
      close(fds[0]);
      dup2(fds[1], 1);
      exec_cmd(cmd_1, shell);
    }
  else
    {
      close(fds[1]);
      dup2(fds[0], 0);
      exec_cmd(cmd_2, shell);
    }
  //Dup les FD pour les sorties

  //exec dans le dup

  //redup pour généré sortie Stand

  //
}

void	exec_pipe(t_cmd *cmds, int pos, t_42sh *shell)
{
  while (cmds[pos].token[0] == '|')
    {
      if (cmds[pos + 1].args[0] == NULL)
	{
	  //args = prompt()
	}
      init_pipes(cmds[pos], cmds[pos + 1], shell);
      pos++;
    }
}
