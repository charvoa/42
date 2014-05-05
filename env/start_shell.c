/*
** start_shell.c for start_shell in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Apr  7 16:15:48 2014 garcia antoine
** Last update Mon May  5 17:02:49 2014 Nicolas Charvoz
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"
#include "listok.h"
#include "../lexer/src/lexer.h"

char	*read_line()
{
  int	nb;
  char	*buffer;
  char	*cmd;

  buffer = malloc(4096 * sizeof(char));
  memset(buffer, '\0', 4096);
  if (buffer == NULL)
    return (0);
  nb = read(0, buffer, 4095);
  if (nb == - 1)
    return (0);
  buffer[nb - 1] = '\0';
  cmd = strdup(buffer);
  free(buffer);
  return (cmd);
}

int	start_shell(t_42sh *shell)
{
  t_token	*token;

  my_clear();
  while (1)
    {
      token = NULL;
      prompt(shell);
      shell->cmd = read_line();
      lexer(shell->cmd, &token, shell);
      free_my_tok(token);
    }
  return (0);
}
