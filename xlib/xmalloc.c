/*
** xmalloc.c for  in /home/charvo_a/42/xlib
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Wed May 21 14:30:17 2014 Nicolas Charvoz
** Last update Thu May 22 13:06:43 2014 Nicolas Charvoz
*/

#include "xlib.h"

void	*xmalloc(size_t size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      fprintf(stderr, "Cannot alloc\n");
      return (NULL);
    }
  return (s);
}

void	*xcalloc(size_t nmemb, size_t size)
{
  void	*s;

  if ((s = calloc(nmemb, size)) == NULL)
    {
      fprintf(stderr, "Cannot calloc\n");
      return (NULL);
    }
  return (s);
}
