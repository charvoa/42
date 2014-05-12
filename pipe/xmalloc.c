/*
** xmalloc.c for  in /home/charvo_a/Work/corewar/asm
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Apr  2 11:26:34 2014 Nicolas Charvoz
** Last update Thu May  1 22:54:52 2014 Serge Heitzler
*/

#include <stdio.h>
#include <stdlib.h>

void	*xmalloc(int size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      printf("Can't perform malloc.\n");
      exit(EXIT_FAILURE);
    }
  return (s);
}
