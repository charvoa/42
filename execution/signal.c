/*
** signal.c for signal in /home/garcia_t/42/execution
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon May 19 11:27:27 2014 garcia antoine
** Last update Mon May 19 11:32:23 2014 garcia antoine
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "../parser/parser.h"
#include "execution.h"

t_signal	l_signal[] =
  {
    {SIGSEGV, "my_segfault2"}
  };

int	check_signal(int status)
{
  int	i;

  i = 0;
  if (status == 0)
    return (0);
  while (l_signal[i].nb)
    {
      if (status == l_signal[i].nb)
	fprintf("%s\n", l_signal[i].msg);
      i++;
    }
  return (-1);
}
