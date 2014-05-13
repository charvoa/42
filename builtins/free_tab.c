/*
** free_struct.c for free_struct in /home/garcia_t/Documents/corewarmerge/asm
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Wed Apr  9 14:47:30 2014 garcia antoine
** Last update Tue May 13 14:29:57 2014 louis audibert
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
