/*
** termcaps.c for  in /home/charvo_a/42/termcaps
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Apr 30 14:23:38 2014 Nicolas Charvoz
** Last update Sat May 24 12:39:29 2014 Nicolas Charvoz
*/

#include "termcaps.h"

int	my_int_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

void    my_clear()
{
  if (tgetent(NULL, "xterm") <= 0)
    {
      my_printf("ERROR\n");
      return (-1);
    }
  tputs(tgetstr("cl", NULL), 1, my_int_putchar);
}
