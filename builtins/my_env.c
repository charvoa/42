/*
** my_env.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Tue May 13 13:38:46 2014 louis audibert
** Last update Thu May 22 16:17:02 2014 Nicolas Charvoz
*/

#include "builtins.h"

int	my_env(t_42sh *shell, char **args, t_dlist *env)
{
  (void)shell;
  (void)args;
  show_list(env);
  return (0);
}
