/*
** my_cd.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May  6 16:42:02 2014 louis audibert
** Last update Mon May 19 22:16:38 2014 garcia antoine
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../env/42sh.h"
#include "../env/list.h"

char	*get_old_pwd(t_dlist *env)
{
  char	*old_pwd;

  old_pwd = get_env("OLDPWD", env);
  if (old_pwd == NULL)
    printf("42sh: cd: OLDPWD not set\n");
  return (old_pwd);
}

char	*get_my_home(t_dlist *env)
{
  char	*home;

  home = get_env("HOME", env);
  if (home == NULL)
    home = "/";
  return (home);
}

char	*get_path_from_opt(char *arg)
{
  char	*path;
  int	i;
  int	j;

  j = 0;
  i = 1;
  path = malloc(strlen(arg) * sizeof(char));
  memset(path, 0, strlen(arg));
  while (arg[i])
    {
      path[j] = arg[i];
      j++;
      i++;
    }
  return (path);
}

void	modify_pwd(char *name, t_dlist *env, int flag)
{
  t_node	*tmp;

  tmp = env->start;
  if (flag == 0)
    {
      while (tmp)
	{
	  if (!strcmp(tmp->name, "PWD"))
	    {
	      tmp->value = strdup(name);
	    }
	  tmp = tmp->next;
	}
    }
  else if (flag == 1)
    {
      while (tmp)
	{
	  if (!strcmp(tmp->name, "OLDPWD"))
	    {
	      tmp->value = strdup(name);
	    }
	  tmp = tmp->next;
	}
    }
}

int    my_cd(t_42sh *shell, char **args, t_dlist *env)
{
  char	*path;

  if (args[1] == NULL)
    {
      chdir(get_my_home(env));
      modify_pwd(get_my_home(env), env, 0);
    }
  else if (args[1][0] == '~')
    {
      path = get_path_from_opt(args[1]);
      chdir(get_my_home(env));
      chdir(path);
    }
  else if (args[1][0] == '-')
    {
      chdir(get_old_pwd(env));
      modify_pwd(get_old_pwd(env), env, 0);
    }
  else if (chdir(args[1]) == -1)
    printf("42sh: cd: No such file or directory\n");
  return (0);
}
