/*
** my_cd.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Tue May  6 16:42:02 2014 louis audibert
** Last update Fri May 23 19:54:51 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

char	*get_old_pwd(t_dlist *env)
{
  char	*old_pwd;

  old_pwd = get_env("OLDPWD", env);
  if (old_pwd == NULL)
    {
      printf("42sh: cd: OLDPWD not set\n");
      return NULL;
    }
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
  path = xcalloc((strlen(arg) + 1), sizeof(char));
  while (arg[i])
    {
      path[j] = arg[i];
      j++;
      i++;
    }
  return (path);
}

int	check_chdir(char *path, t_dlist *env)
{
  int	check;

  check = chdir(path);
  if (check == -1)
    {
      printf("42sh: cd: No such file or directory\n");
      return (-1);
    }
  modif_oldpwd(get_env("PWD", env), env);
  modif_simple_pwd(path, env);
  return (0);
}

int    my_cd(t_42sh *shell, char **args, t_dlist *env)
{
  char	*path;

  (void)shell;
  if (args[1] == NULL)
    {
      chdir(get_my_home(env));
      modif_oldpwd(get_env("PWD", env), env);
      modif_pwd_home(get_my_home(env), env);
    }
  else if (args[1][0] == '~' && args[1][1] != '~'
	   && !((args[1][1] >= 'a' && args[1][1] <= 'z')
		|| (args[1][1] >= 'A' && args[1][1] <= 'Z')))
    {
      path = get_path_from_opt(args[1]);
      chdir(get_my_home(env));
      chdir(path);
      modif_oldpwd(get_env("PWD", env), env);
      modif_pwd_from_home_to_path(args[1], env);
    }
  else if (args[1][0] == '-')
    {
      chdir(get_old_pwd(env));
      modif_oldpwd(get_old_pwd(env), env);
    }
  else
    check_chdir(args[1], env);
  return (0);
}
