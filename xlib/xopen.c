/*
** xopen.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:08:01 2014 Nicolas Charvoz
** Last update Thu May 22 13:07:45 2014 Nicolas Charvoz
*/

#include "xlib.h"

int	xopenmode(const char *pathname, int flags, mode_t mode)
{
  int	fd;

  if ((fd = open(pathname, flags, mode)) == -1)
    {
      fprintf(stderr, "Cannot Open file : %s\n", pathname);
      return (-1);
    }
  return (fd);
}

int	xopen(const char *pathname, int flags)
{
  int	fd;

  if ((fd = open(pathname, flags)) == -1)
    {
      fprintf(stderr, "Cannot Open file : %s\n", pathname);
      return (-1);
    }
  return (fd);
}

int	xcreat(const char *pathname, mode_t mode)
{
  int	fd;

  if ((fd = creat(pathname, mode)) == -1)
    {
      fprintf(stderr, "Cannot create file : %s\n", pathname);
      return (-1);
    }
  return (fd);
}
