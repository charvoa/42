/*
** main.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May 13 11:20:48 2014 louis audibert
** Last update Tue May 13 15:15:19 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./42sh.h"

int     main(int ac, char **av, char **env)
{
  t_42sh        *shell;
  char  *cmd;
  char  **opt;
  char  *path;

  cmd = "echo";
  opt = malloc(2 * sizeof(char*));
  opt[0] = "$HOME";
  opt[1] = NULL;
  shell = malloc(sizeof(t_42sh*));
  init_my_shell(shell, env);
  check_builtin(cmd, opt, shell->env);
}
