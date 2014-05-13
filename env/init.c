/*
** init.c for init in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:34:07 2014 garcia antoine
<<<<<<< Updated upstream
** Last update Tue May 13 14:01:39 2014 garcia antoine
=======
** Last update Mon May  5 17:00:21 2014 garcia antoine
>>>>>>> Stashed changes
*/

#include <stdlib.h>
#include "42sh.h"

t_dlist	*create_my_env(t_dlist *shell, char **environ)
{
  int	i;
  char	*name;
  char	*value;

  i = 0;
  if((shell = create_list()) == NULL)
    return (EXIT_FAILURE);
  while (environ[i])
    {
      name = get_name_from_env(environ[i]);
      value = get_value_from_env(environ[i]);
      put_in_list(shell, name, value);
      i++;
    }
  return (shell);
}

int	init_my_shell(t_42sh *shell, char **env)
{
  char	*path;

  shell->env = create_my_env(shell->env, env);
  path  = get_env("PATH", shell->env);
  if (path == NULL)
    return (0);
  shell->path = strtotab(path);
  shell->envtab = list_to_tab(shell->env);
  return (0);
}
