/*
** signal.c for signal in /home/garcia_t/42/execution
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Mon May 19 11:27:27 2014 garcia antoine
** Last update Sat May 24 06:20:40 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "../parser/parser.h"
#include "execution.h"

t_signal	g_signal[] =
  {
    {SIGSEGV, "Segmentation fault"},
    {SIGBUS, "Bus error"},
    {SIGABRT, "Abort"},
    {SIGFPE, "Floating point exception"},
    {SIGILL, "Illegal instruction"},
    {SIGKILL, "Killed"},
    {SIGPIPE, "Broken pipe"},
    {SIGCHLD, "Child stop"},
    {SIGXCPU, "CPU limit reached"},
    {SIGTERM, "Terminated"},
    {SIGUSR1, "User signal 1"},
    {SIGUSR2, "User signal 2"}
  };

int	check_signal(int status)
{
  int	i;

  i = 0;
  if (status == 0)
    return (0);
  while (l_signal[i].nb)
    {
      if (status == g_signal[i].nb)
	fprintf(stderr, "%s\n", g_signal[i].msg);
      i++;
    }
  return (-1);
}
