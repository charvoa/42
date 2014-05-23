/*
** my_env.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May 13 13:38:46 2014 louis audibert
** Last update Sat May 17 17:42:43 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../env/42sh.h"
#include "../env/list.h"

int	my_env(t_42sh *shell, char **args, t_dlist *env)
{
  show_list(env);
  return (0);
}
