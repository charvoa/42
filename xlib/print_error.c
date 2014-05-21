/*
** print_error.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:11:39 2014 Nicolas Charvoz
** Last update Wed May 21 14:28:56 2014 Nicolas Charvoz
*/

#include "xlib.h"

void	print_error(char *str)
{
  write(2, str, (strlen(str) + 1));
}
