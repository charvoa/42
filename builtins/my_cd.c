/*
** my_cd.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May  6 16:42:02 2014 louis audibert
** Last update Tue May 13 15:16:21 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"

char	*get_old_pwd(t_dlist *env)
{
  char	*old_pwd;

  old_pwd = get_env("OLDPWD", env);
  if (old_pwd == NULL)
    my_putstre("42sh: cd: OLDPWD not set\n");
  return (old_pwd);
}

char	*get_my_home(t_dlist *env)
{
  char	*home;

  home = get_env("HOME", env);
  if (home == NULL)
    chdir("/");
  return (home);
}

char	*get_path_from_opt(char *opt)
{
  char	*path;
  int	i;
  int	j;

  j = 0;
  i = 1;
  path = malloc(strlen(opt) * sizeof(char));
  memset(path, 0, strlen(opt));
  while (opt[i])
    {
      path[j] = opt[i];
      j++;
      i++;
    }
  return (path);
}

void    my_cd(char **opt, t_dlist *env)
{
  char	*path;

  path = get_path_from_opt(opt[0]);
  if (opt[0] == NULL || opt[0][0] == '~')
    {
      chdir(get_my_home(env));
      if (opt[0][0] == '~')
	{
	  printf("%s\n", path);
	  chdir(path);
	}
      printf("chdir(home)\n");
    }
  else if (opt[0][0] == '-')
    {
      chdir(get_old_pwd(env));
      printf("chdir(oldpwd)\n");
    }
  else if (chdir(opt[0]) == -1)
    {
      my_putstre("42sh: cd: No such file or directory\n");
    }
  else
    {
      chdir(opt[0]);
      printf("chdir(opt[0])\n");
    }
}
