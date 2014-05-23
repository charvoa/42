/*
** my_cd.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Tue May  6 16:42:02 2014 louis audibert
** Last update Fri May 23 23:23:20 2014 louis audibert
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

  if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
    {
      if (access(path, F_OK) == -1)
        fprintf(stderr, "42sh: cd: No such file or directory.\n");
      else
	fprintf(stderr, "42sh: cd: Permission Denied");
      return (-1);
    }
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
  (void)shell;
  if (args[1] == NULL)
    {
      if (cd_home(env) == -1)
	return (-1);
    }
  else if (args[1][0] == '~' && args[1][1] != '~'
	   && !((args[1][1] >= 'a' && args[1][1] <= 'z')
		|| (args[1][1] >= 'A' && args[1][1] <= 'Z')))
    {
      if (cd_tild(args, env) == -1)
	return (-1);
    }
  else if (args[1][0] == '-')
    {
      if (cd_dash(env) == -1)
	return (-1);
    }
  else
    {
      if (args[1][0] == '.' && args[1][1] == '\0')
	return (0);
      if (check_chdir(args[1], env) == -1)
	return (-1);
    }
  return (0);
}
