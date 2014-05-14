/*
** global_exec.c for global_exec in /home/garcia_t/42/execution

** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Thu May  8 16:21:37 2014 garcia antoine
<<<<<<< HEAD
** Last update Wed May 14 15:47:24 2014 garcia antoine
=======
** Last update Wed May 14 14:32:41 2014 Nicolas Girardot
>>>>>>> c59b120f6e2be93a02bf453db16bcc9b31c4fadf
*/

#include <unistd.h>
#include "../parser/parser.h"
#include "execution.h"

int	global_exec(t_cmd *cmd, t_42sh *shell, int tok)
{
  int	i;

  i = 0;
  while (cmd[i].token != NULL)
    {
      if ((cmd[i].token == NULL || !(strcmp(cmd[i].token, ";"))) && cmd[i].type == 0)
	exec_cmd_simple(&cmd[i], shell);
      else if (!strcmp(cmd[i].token, ">") || !strcmp(cmd[i].token, ">>") || !strcmp(cmd[i].token, "<"))
	redirections(&cmd[i], &cmd[i + 1], shell);
      i++;
      tok--;
    }
  return (0);
}
