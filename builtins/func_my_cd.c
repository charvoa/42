/*
** func_my_cd.c for 42sh in /home/audibe_l/rendu/42sh/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri May 23 21:29:41 2014 louis audibert
** Last update Sat May 24 00:26:32 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"


void		modif_path_to_root(t_dlist *env)
{
  t_node	*tmp;

  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strcpy(tmp->value, "/");
      tmp = tmp->next;
    }
}

int		check_access(t_dlist *env)
{
  if (access(get_my_home(env), F_OK) == -1 || access(get_my_home(env), R_OK) == -1)
    {
      if (access(get_my_home(env), F_OK) == -1)
        fprintf(stderr, "42sh: cd: No such file or directory.\n");
      else
	fprintf(stderr, "42sh: cd: Permission Denied");
      return (-1);
    }
  return (0);
}

int		cd_home(t_dlist *env)
{
  if (check_access(env) == -1)
    return (-1);
  chdir(get_my_home(env));
  modif_oldpwd(get_env("PWD", env), env);
  modif_pwd_home(get_my_home(env), env);
  return (0);
}

int		cd_tild(char **args, t_dlist *env)
{
  char		*path;

  path = get_path_from_opt(args[1]);
  if (check_access(env) == -1)
    return (-1);
  chdir(get_my_home(env));
  if (access(path, R_OK) == -1)
    {
      fprintf(stderr, "42sh: cd: Permission Denied.\n");
      return (-1);
    }
  chdir(path);
  modif_oldpwd(get_env("PWD", env), env);
  modif_pwd_from_home_to_path(args[1], env);
  return (0);
}

int		cd_dash(t_dlist *env)
{
  if (access(get_old_pwd(env), F_OK) == -1 || access(get_old_pwd(env), R_OK) == -1)
    {
      if (access(get_old_pwd(env), F_OK) == -1)
        fprintf(stderr, "42sh: cd: No such file or directory.\n");
      else
	fprintf(stderr, "42sh: cd: Permission Denied");
      return (-1);
    }
  chdir(get_old_pwd(env));
  modif_oldpwd(get_old_pwd(env), env);
  return (0);
}
