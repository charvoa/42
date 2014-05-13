/*
** my_exit.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May 13 11:21:57 2014 louis audibert
** Last update Tue May 13 11:28:28 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"

void    my_exit(char *buffer)
{
  if (strcmp(buffer, "exit\n") == 0)
    exit(0);
}
