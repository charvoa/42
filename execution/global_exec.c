/*
** global_exec.c for global_exec in /home/garcia_t/42/execution

** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Thu May  8 16:21:37 2014 garcia antoine
** Last update Sat May 17 15:29:34 2014 garcia antoine

*/

#include <unistd.h>
#include "../parser/parser.h"
#include "execution.h"

int	global_exec(t_cmd *cmd, t_42sh *shell, int tok)
{
  int	i;

  i = 0;
  while (tok != 0)
    {
      if ((cmd[i].token == NULL || !(strcmp(cmd[i].token, ";"))) && (cmd[i].type == 0))
	exec_cmd_simple(&cmd[i], shell);
      else if (cmd[i].token && (!strncmp(cmd[i].token, ">", 1)
				|| !strncmp(cmd[i].token, ">>", 2) || !strncmp(cmd[i].token, "<", 1)))
	redirections(&cmd[i], &cmd[i + 1], shell);
      else if (cmd[i].token && (!strcmp(cmd[i].token, "|")))
	init_pipes(&cmd[i], &cmd[i + 1], shell);
      my_segfault(cmd->status);
      i++;
      tok--;
    }
  return (0);
}
