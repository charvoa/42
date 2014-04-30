/*
** prompt.c for prompt in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 15:59:36 2014 garcia antoine
** Last update Wed Apr 30 14:24:08 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"
#include "../termcaps/termcaps.h"
#include "./libsources/my.h"

static char	*get_pwd_from_env(t_dlist *env)
{
  if (get_env("PWD", env) == NULL)
    return (" ");
  return (get_env("PWD", env));
}

static char	*get_user_from_env(t_dlist *env)
{
  if (get_env("USER", env) == NULL)
    return ("user");
  return (get_env("USER", env));
}

static char    *get_host_from_env(t_dlist *env)
{
  if (get_env("HOSTNAME", env) == NULL)
    return ("localhost");
  return (get_env("HOSTNAME", env));
}

void	prompt(t_42sh *shell)
{
  char	*pwd;
  char	*host;
  char	*user;

  pwd = get_pwd_from_env(shell->env);
  user = get_user_from_env(shell->env);
  host = get_host_from_env(shell->env);
  my_clear();
  my_printf("\033[36m%s\033[0m@\033[35m%s\033[0m: %s: ", user, host, pwd);
}
