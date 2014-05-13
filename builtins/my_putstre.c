/*
** my_putstre.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May 13 11:21:26 2014 louis audibert
** Last update Tue May 13 11:28:45 2014 louis audibert
*/

#include <string.h>

int     my_putstre(char *str)
{
  write(2, str, strlen(str));
  return (0);
}
