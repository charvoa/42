/*
** init.c for init in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:34:07 2014 garcia antoine
<<<<<<< Updated upstream
** Last update Tue May 13 13:18:41 2014 louis audibert
=======
** Last update Mon May  5 17:00:21 2014 garcia antoine
>>>>>>> Stashed changes
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"

int     isolate_name_and_value_from_env(char *env)
{
  int   i;

  i = 0;
  while (env[i])
    {
      if (env[i] == '=')
        return (i);
      i++;
    }
  return (0);
}

char    *get_name_from_env(char *env)
{
  int   size;
  char  *name;

  size = isolate_name_and_value_from_env(env);
  if ((name = strndup(env, size)) == NULL)
    return (NULL);
  return (name);
}

char    *get_value_from_env(char *env)
{
  char  *value;
  int   size;

  size = isolate_name_and_value_from_env(env);
  if ((value = strndup(env + (size + 1), strlen(env + size))) == NULL)
    return (NULL);
  return (value);
}

int	create_my_env(t_42sh *shell, char **environ)
{
  int	i;
  char	*name;
  char	*value;

  i = 0;
  if((shell->env = create_list()) == NULL) // SEGFAULT shell->env est vide
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

char    **list_to_tab(t_dlist *env)
{
  char  **tab;
  t_node *tmp;
  int   i;

  i = 0;
  tmp = env->start;
  tab = malloc((env->lenght + 1) * sizeof(char *));
  if (tab == NULL)
    return (NULL);
  while (tmp)
    {
      tab[i] = malloc(strlen(tmp->name) + strlen(tmp->value) + 2 * sizeof(char));
      tab[i] = strcpy(tab[i], tmp->name);
      tab[i] = strcat(tab[i], "=");
      tab[i] = strcat(tab[i], tmp->value);
      tmp = tmp->next;
      i++;
    }
  tab[i] = '\0';
  return (tab);
}


int	init_my_shell(t_42sh *shell, char **env)
{
  char	*path;

  create_my_env(shell, env);
  path  = get_env("PATH", shell->env);
  if (path == NULL)
    return (0);
  shell->path = strtotab(path);
  shell->envtab = list_to_tab(shell->env);
  return (0);
}
