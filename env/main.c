/*
** main.c for main in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:20:14 2014 garcia antoine
** Last update Sat May  3 14:51:39 2014 Nicolas Charvoz
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

void	free_struct_shell(t_42sh *shell)
{
  if (shell->env->lenght > 0)
    free_my_list(shell->env);
  if (shell->cmd != NULL)
    free(shell->cmd);
}

int	main(int ac, char **av, char **env)
{
  t_42sh	shell;
  (void)	ac;
  (void)	av;

  init_my_shell(&shell, env);
  start_shell(&shell);
  free_struct_shell(&shell);
  return (0);
}
