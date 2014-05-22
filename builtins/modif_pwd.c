/*
** modif_pwd.c for 42sh in /home/audibe_l/rendu/42sh/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Mon May 19 22:43:20 2014 louis audibert
** Last update Thu May 22 16:05:26 2014 Nicolas Charvoz
*/

#include "builtins.h"

char	*clean_arg(char *arg)
{
  int	i;
  int	j;
  char	*clean_arg;

  clean_arg = malloc(strlen(arg) * sizeof(char));
  memset(clean_arg, 0, strlen(arg));
  i = 0;
  j = 0;
  while (arg[i] == '.' && arg[i + 1] == '.' && arg[i + 2] == '/')
    i += 3;
  while (arg[i])
    {
      clean_arg[j] = arg[i];
      j++;
      i++;
    }
  clean_arg[j] = '\0';
  printf("clean_arg = %s\n", clean_arg);
  return (clean_arg);
}

void		modif_simple_pwd(char *arg, t_dlist *env)
{
  t_node        *tmp;
  char		*name;

  tmp = env->start;
  name = parse_name(arg, get_env("PWD", env));
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = name;
      tmp = tmp->next;
    }
}

void		modif_pwd_from_home_to_path(char *name, t_dlist *env)
{
  t_node        *tmp;
  char		*pwd;

  pwd = malloc(strlen(name) * sizeof(char));
  memset(pwd, '\0', strlen(name));
  printf("TEST\n");
  pwd = get_pwd_from_home(pwd, name, env);
  printf("TEST 2\n");
  pwd = strcat(get_my_home(env), pwd);
  printf("TEST 3\n");
  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strdup(pwd);
      tmp = tmp->next;
    }
}

void		modif_pwd_home(char *name, t_dlist *env)
{
  t_node        *tmp;

  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strdup(name);
      tmp = tmp->next;
    }
}

int		modif_oldpwd(char *name, t_dlist *env)
{
  t_node	*tmp;
  char		*save;

  tmp = env->start;
  save = get_env("PWD", env);
  if (save == NULL)
    {
      printf("42sh: cd: OLDPWD not set\n");
      return (-1);
    }
  while (tmp)
    {
      if (!strcmp(tmp->name, "PWD"))
	tmp->value = strdup(name);
      tmp = tmp->next;
    }
  tmp = env->start;
  while (tmp)
    {
      if (!strcmp(tmp->name, "OLDPWD"))
	tmp->value = strdup(save);
      tmp = tmp->next;
    }
  return (0);
}
