/*
** useless.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May  5 10:25:59 2014 Nicolas Charvoz
** Last update Mon May  5 10:27:27 2014 Nicolas Charvoz
*/

#include "parser.h"

void	show_pars(t_pars *pars)
{
  int	i;

  i = 0;
  while (pars->tab[i])
    {
      printf("tab[%d] => %s\n", i, pars->tab[i]);
      i++;
    }
}
