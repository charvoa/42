/*
** my_cd.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May  6 16:42:02 2014 louis audibert
** Last update Mon May 19 15:57:32 2014 louis audibert
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

int    my_cd(t_42sh *shell, char **args, t_dlist *env)
{
  char	*path;

  if (args[1] == NULL)
    chdir(get_my_home(env));
  else if (args[1][0] == '~')
    {
      path = get_path_from_opt(args[1]);
      chdir(get_my_home(env));
      chdir(path);
    }
  else if (args[1][0] == '-')
    chdir(get_old_pwd(env));
  else if (chdir(args[1]) == -1)
    printf("42sh: cd: No such file or directory\n");
  return (0);
}
