/*
** xmalloc.c for xmalloc.c in /home/charvo_a/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat May 24 12:37:36 2014 Nicolas Charvoz
** Last update Sat May 24 12:37:38 2014 Nicolas Charvoz
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
