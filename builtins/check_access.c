/*
** check_access.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Sat May 24 06:10:26 2014 louis audibert
** Last update Sat May 24 06:18:10 2014 Nicolas Charvoz
*/

#include "builtins.h"
#include "../xlib/xlib.h"

int	check_access(t_dlist *env)
{
  if (access(get_my_home(env), F_OK) == -1
      || access(get_my_home(env), R_OK) == -1)
    {
      if (access(get_my_home(env), F_OK) == -1)
        fprintf(stderr, "42sh: cd: No such file or directory.\n");
      else
        fprintf(stderr, "42sh: cd: Permission Denied\n");
      return (-1);
    }
  return (0);
}
