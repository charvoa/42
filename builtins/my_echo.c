/*
** my_echo.c for 42sh in /home/audibe_l/rendu/42/builtins
** 
** Made by louis audibert
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  8 11:33:49 2014 louis audibert
** Last update Thu May  8 13:27:29 2014 louis audibert
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	echo_from_var_env(char *var_env, char **my_env)
{
  int	i;
  int	j;
  int	k;
  char	*clean_var_env;

  clean_var_env = malloc((strlen(var_env) - 1) * sizeof(char));
  memset(clean_var_env, '\0', (strlen(var_env) - 1));
  i = 0;
  j = 0;
  k = 0;
  while (var_env[j + 1])
    {
      clean_var_env[j] = var_env[j + 1];
      j++;
    }
  //  printf("%s\n", clean_var_env);
  while (my_env[i])
    {
      if (strncmp(clean_var_env, my_env[i], strlen(clean_var_env)) == 0)
	{
	  while (my_env[i][k] != '=')
	    k++;
	  printf("%s\n", &my_env[i][k + 1]);
	  return (0);
	}
      i++;
    }
  putchar('\n');
  return (-1);
}

int	my_echo(char **opt, char **my_env)
{
  char	*var_env;
  int	i;

  i = 0;
  var_env = malloc(strlen(opt[0]) * sizeof(char));
  memset(var_env, '\0', strlen(opt[0]));
  if (opt[0][0] == '$')
    {
      var_env = opt[0];
      echo_from_var_env(var_env, my_env);
      return (0);
    }
  else
    {
      while (opt[i] != NULL)
	{
	  printf("%s", opt[i]);
	  i++;
	}
      putchar('\n');
      return (0);
    }  
}
