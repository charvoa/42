/*
** main.c for main in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:20:14 2014 garcia antoine
** Last update Sat May 24 01:52:52 2014 garcia antoine
*/

#include <stdlib.h>
#include "42sh.h"
#include "listok.h"

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

int	main(int ac, char **av, char **env)
{
  (void)	ac;
  (void)	av;
  init_my_shell(&shell, env);
  if (start_shell(&shell) == -42)
    return (shell.exit_value);
  return (0);
}
