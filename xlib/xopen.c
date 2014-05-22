/*
** xopen.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:08:01 2014 Nicolas Charvoz
** Last update Thu May 22 11:56:57 2014 heitzl_s
*/

#include "xlib.h"

int	xopenmode(const char *pathname, int flags, mode_t mode)
{
  int	fd;

  if ((fd = open(pathname, flags, mode)) == -1)
    {
      print_error("Cannot Open file :");
      print_error(pathname);
      print_error("\n");
      return (-1);
    }
  return (fd);
}

int	xopen(const char *pathname, int flags)
{
  int	fd;

  if ((fd = open(pathname, flags)) == -1)
    {
      print_error("Cannot Open file :");
      print_error(pathname);
      print_error("\n");
      return (-1);
    }
  return (fd);
}

int	xcreat(const char *pathname, mode_t mode)
{
  int	fd;

  if ((fd = creat(pathname, mode)) == -1)
    {
      print_error("Cannot create file :" );
      print_error(pathname);
      print_error("\n");
      return (-1);
    }
  return (fd);
}
