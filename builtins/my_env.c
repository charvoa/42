/*
** my_env.c for 42sh in /home/audibe_l/rendu/42/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Tue May 13 13:38:46 2014 louis audibert
** Last update Sat May 24 00:54:42 2014 louis audibert
*/

#include "builtins.h"

int	my_env(t_42sh *shell, t_cmd *cmd, t_dlist *env)
{
  (void)shell;
  (void)cmd;
  show_list(env);
  return (0);
}
