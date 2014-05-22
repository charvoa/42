/*
** xread.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:15:07 2014 Nicolas Charvoz
** Last update Thu May 22 13:01:44 2014 Nicolas Charvoz
*/

#include "xlib.h"

ssize_t	xread(int fd, void *buf, size_t count)
{
  int	nb;

  if ((nb = read(fd, buf, count)) == -1)
    {
      fprintf(stderr, "Cannot Read file\n");
      return (-1);
    }
  return (nb);
}
