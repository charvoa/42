/*
** my_env.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May 13 13:38:46 2014 louis audibert
** Last update Tue May 13 15:16:11 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"
#include "./list.h"

void	my_env(char **opt, t_dlist *env)
{
  show_list(env);
}
