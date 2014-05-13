/*
** start_shell.c for start_shell in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Apr  7 16:15:48 2014 garcia antoine
** Last update Tue May 13 14:35:49 2014 Nicolas Charvoz
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include "42sh.h"
#include "listok.h"
#include "../lexer/src/lexer.h"

t_42sh	shell;

void	get_sigint(int sig)
{
  sig = sig;
  printf("\n");
  prompt(&shell);
}


char	*read_line(int fd)
{
  int	nb;
  char	*buffer;
  char	*cmd;

  buffer = malloc(4096 * sizeof(char));
  memset(buffer, '\0', 4096);
  if (buffer == NULL)
    return (0);
  nb = read(0, buffer, 4095);
  if (nb == -1)
    return (0);
  buffer[nb - 1] = '\0';
  if (strcmp(buffer, "exit") == 0)
    {
      remove(".hist42sh");
      exit(0);
    }
  cmd = strdup(buffer);
  free(buffer);
  cmd = epur_str(cmd);
  write(fd, cmd, strlen(cmd));
  write(fd, "\n", 1);
  return (cmd);
}

int	start_shell(t_42sh *shell)
{
  t_token	*token;
  int		fd;

  fd = creat(".hist42sh", 0644);
  my_clear();
  while (1)
    {
      token = NULL;
      signal(SIGINT, get_sigint);
      prompt(shell);
      shell->cmd = read_line(fd);
      lexer(shell->cmd, &token, shell);
      free_my_tok(token);
    }
  return (0);
}
