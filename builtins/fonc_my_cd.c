/*
** fonc_my_cd.c for 42sh in /home/audibe_l/rendu/42sh/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri May 23 21:29:41 2014 louis audibert
** Last update Fri May 23 21:35:23 2014 louis audibert
*/

#include "builtins.h"
#include "../xlib/xlib.h"

void	cd_home(t_dlist *env)
{
  chdir(get_my_home(env));
  modif_oldpwd(get_env("PWD", env), env);
  modif_pwd_home(get_my_home(env), env);
}

void	cd_tild(char **args, t_dlist *env)
{
  char	*path;

  path = get_path_from_opt(args[1]);
  chdir(get_my_home(env));
  chdir(path);
  modif_oldpwd(get_env("PWD", env), env);
  modif_pwd_from_home_to_path(args[1], env);
}

void	cd_dash(t_dlist *env)
{
  chdir(get_old_pwd(env));
  modif_oldpwd(get_old_pwd(env), env);
}
