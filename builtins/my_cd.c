/*
** my_cd.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue May  6 16:42:02 2014 louis audibert
** Last update Thu May  8 13:28:23 2014 louis audibert
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include "../42sh.h"
#define BUF_SIZE 4096

int     my_putstre(char *str)
{
  write(2, str, strlen(str));
  return (0);
}

int     len_env(char **env)
{
  int   i;

  i = 0;
  while (env[i])
    i++;
  return (i);
}

char    **get_my_env(char **env)
{
  int   i;
  char  **my_env;

  i = 0;
  my_env = malloc((len_env(env) + 1) * (sizeof (char*)));
  while (env[i])
    {
      my_env[i] = strdup(env[i]);
      my_env[i][strlen(my_env[i])] = '\0';
      i++;
    }
  my_env[i] = NULL;
  return (my_env);
}

char	*get_old_pwd(char **my_env)
{
  char	*old_pwd;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 7;
  k = 0;
  old_pwd = malloc(sizeof(char) * BUF_SIZE);
  memset(old_pwd, '\0', BUF_SIZE);
  while (my_env[i] != NULL)
    {
      if (strncmp(my_env[i], "OLDPWD=", 7) == 0)
	{
	  while (my_env[i][j] != '\0')
	    {
	      old_pwd[k] = my_env[i][j];
	      /* printf("old_pwd[%d] = %c\n", k, old_pwd[k]); */
	      /* printf("%s\n", old_pwd); */
	      /* printf("------------------\n"); */
	      k++;
	      j++;
	    }
	}
      i++;
    }
  old_pwd[k] = '\0';
  if (old_pwd == "\0")
    {
      my_putstre("42sh: cd: OLDPWD not set\n");
      /* printf("TEST\n"); */
    }
  printf("%s\n", old_pwd);
  return (old_pwd);
}

char	*get_my_home(char **my_env)
{
  char	*str;
  int	i;
  int	j;
  int	k;
  int	flag;

  i = 0;
  flag = 0;
  str = malloc(sizeof(char) * BUF_SIZE);
  memset(str, '\0', BUF_SIZE);
  while (my_env[i] != NULL)
    {
      if (strncmp(my_env[i], "HOME=", 5) == 0)
	{
	  flag = 1;
	  j = 5;
	  k = 0;
	  while (my_env[i][j])
	    str[k++] = my_env[i][j++];
	}
      i++;
    }
  if (flag == 0)
    chdir("/");
  return (str);
}

void    my_cd(char *cmd, char **opt, char **my_env)
{
  char  *home;

  home = get_my_home(my_env);
  if (opt[0] == NULL)
    chdir(home);
  else if (chdir(opt[0]) == -1)
    my_putstre("cd: No such file or directory\n");
}

void    aff_my_env(char **my_env)
{
  int   i;

  i = 0;
  while (my_env[i])
    {
      puts(my_env[i]);
      i++;
    }
}

int     check_builtin(char *cmd, char **opt, char **my_env)
{
  if (strcmp(cmd, "cd") == 0)
    {
      if (strcmp(opt[0], "-") == 0)
	{
	  opt[0] = get_old_pwd(my_env);
	}
      my_cd(cmd, opt, my_env);
      return (0);
    }
  else if (strcmp(cmd, "env") == 0)
    {
      aff_my_env(my_env);
      return (0);
    }
  else if (strcmp(cmd, "echo") == 0)
    my_echo(opt, my_env);
  else
    return (-1);
}

void    my_exit(char *buffer)
{
  if (strcmp(buffer, "exit\n") == 0)
    exit(0);
}

int	main(int ac, char **av, char **env)
{
  char	**my_env;
  char	*cmd;
  char	**opt;

  cmd = "echo";
  opt = malloc(2 * sizeof(char*));
  opt[0] = "$PWD";
  opt[1] = NULL;
  my_env = get_my_env(env);
  check_builtin(cmd, opt, my_env);
  return (0);
}
