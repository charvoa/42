/*
** xpipe.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:20:51 2014 Nicolas Charvoz
** Last update Thu May 22 12:49:36 2014 Nicolas Girardot
*/

#include "xlib.h"

int	*xpipe(int *pipefd)
{
  if ((pipe(pipefd) == -1)
    {
      print_error("Cannot open pipe\n");
      return (-1);
    }
  return (0);
}
