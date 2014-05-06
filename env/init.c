/*
** init.c for init in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:34:07 2014 garcia antoine
<<<<<<< Updated upstream
** Last update Mon May  5 17:00:50 2014 Nicolas Charvoz
=======
** Last update Mon May  5 17:00:21 2014 garcia antoine
>>>>>>> Stashed changes
*/

#include <stdlib.h>
#include "42sh.h"

int	create_my_env(t_42sh *shell, char **environ)
{
  int	i;
  char	*name;
  char	*value;

  i = 0;
  if((shell->env = create_list()) == NULL)
    return (EXIT_FAILURE);
  while (environ[i])
    {
      name = get_name_from_env(environ[i]);
      value = get_value_from_env(environ[i]);
      put_in_list(shell->env, name, value);
      i++;
    }
  return (0);
}

void	init_my_shell(t_42sh *shell, char **env)
{
  create_my_env(shell, env);
  shell->envtab = list_to_tab(shell->env);
}
