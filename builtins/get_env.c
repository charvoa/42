/*
** get_env.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May 13 11:23:16 2014 louis audibert
** Last update Tue May 13 11:31:42 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"
#include "./list.h"

char    *get_env(char *name, t_dlist *env)
{
  t_node        *tmp;

  tmp = env->start;
  while (tmp)
    {
      if (strcmp(name, tmp->name) == 0)
        return (tmp->value);
      tmp = tmp->next;
    }
  return (NULL);
}
