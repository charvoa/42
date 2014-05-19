/*
** start_shell.c for start_shell in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Apr  7 16:15:48 2014 garcia antoine
** Last update Mon May 19 19:04:35 2014 Nicolas Girardot
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <term.h>
#include <curses.h>
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

char	*cat_if_pipe(char *cmd)
{
  char	*buffer;
  int	ret;

  buffer = calloc(4096, sizeof(char));
  my_putchar('>');
  ret = read(0, buffer, 4096);
  buffer[ret - 1] = '\0';
  cmd = strcat(cmd, buffer);
  if (cmd[strlen(cmd) - 1] == '|')
    cmd = cat_if_pipe(cmd);
  return (cmd);
}

char	*read_canon()
{
  char		buffer[4096];
  struct	termios	*t;
  int		nb;

  t = malloc(sizeof(*t));
  if (tcgetattr(0, t) == -1)
    {
      printf("Error\n");
      exit(-1);
    }
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if(tcsetattr(0, TCSANOW, t) == - 1)
    {
      printf("Error\n");
      exit(-1);
    }
  nb = read(0, buffer, 4096);
  buffer[nb - 1] = '\0';
  return (buffer);
}

char	*read_line(int fd)
{
  int	nb;
  char	*buffer;
  char	*cmd;

  buffer= read_canon();
  cmd = strdup(buffer);
  free(buffer);
  cmd = epur_str(cmd);
  if (cmd[nb - 2] == '|')
    cmd = cat_if_pipe(cmd);
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
