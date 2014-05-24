/*
** my_history.c for 42sh in /home/audibe_l/rendu/42sh/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Mon May 19 18:58:39 2014 louis audibert
** Last update Sat May 24 02:23:52 2014 heitzl_s
*/

#include "builtins.h"
#include "../xlib/xlib.h"

int	restricted_history(char *buffer, char *restricted)
{
  int	nb;
  int	i;

  i = 0;
  while (restricted[i])
    {
      if (restricted[i] <= '0' && restricted[i] >= '9')
	{
	  printf("history: %s: Invalid option\n", restricted);
	  return (-1);
	}
      i++;
    }
  nb = atoi(restricted);
  if (nb > 0)
    {
      disp_history_from_line(buffer, nb);
      return (0);
    }
  else
    {
      printf("history: %s: Invalid option\n", restricted);
      return (-1);
    }
}

int	my_history(t_42sh *shell, t_cmd *cmd, t_dlist *env, int i)
{
  int	fd;
  int	nb;
  char	*buffer;
  char	*final;

  (void)shell;
  (void)env;
  buffer = xmalloc(4096 * sizeof(char));
  final = xmalloc(4096 * sizeof(char));
  memset(final, 0, 4096);
  memset(buffer, 0, 4096);
  fd = xopen(".hist42sh", O_CREAT | S_IRUSR | S_IRGRP | S_IROTH);
  while ((nb = read(fd, buffer, 4096)) != 0)
    {
      final = realloc(final, 4096);
      final = strcat(final, buffer);
      memset(buffer, 0, 4095);
    }
  if (cmd[i].args[1] && strcmp(cmd[i].args[1], "-c") == 0)
    remove(".hist42sh");
  else if (cmd[i].args[1] && cmd[i].args[1][0] >= '0' && cmd[i].args[1][0] <= '9')
    restricted_history(final, cmd[i].args[1]);
  else if (cmd[i].args[1] == NULL)
    printf("%s", final);
  return (0);
}
