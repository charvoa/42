/*
** xmalloc.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:30:17 2014 Nicolas Charvoz
** Last update Wed May 21 14:35:58 2014 Nicolas Charvoz
*/

#include "xlib.h"

void	*xmalloc(size_t size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      print_error("Cannot alloc\n");
      return (NULL);
    }
  return (s);
}

void	*xcalloc(size_t nmemb, size_t size)
{
  void	*s;

  if ((s = calloc(nmemb, size)) == NULL)
    {
      print_error("Cannot calloc\n");
      return (NULL);
    }
  return (s);
}
