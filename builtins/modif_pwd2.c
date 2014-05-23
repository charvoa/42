/*
** modif_pwd2.c for 42sh in /home/audibe_l/rendu/42sh/builtins
**
** Made by louis audibert
** Login   <audibe_l@epitech.net>
**
** Started on  Tue May 20 14:26:40 2014 louis audibert
** Last update Fri May 23 10:31:03 2014 heitzl_s
*/

#include "builtins.h"
#include "../xlib/xlib.h"

char	*get_pwd_from_home(char *pwd, char *name, t_dlist *env)
{
  int	i;
  int	j;

  (void)env;
  i = 1;
  j = 0;
  while (name[i])
    {
      pwd[j] = name[i];
      j++;
      i++;
    }
  return (pwd);
}

char    *check_name(char *name)
{
  int   i;

  i = 0;
  while (name[i])
    {
      if (name[i] == '/' && name[i + 1] == '/')
        {
          while (name[i + 1])
            {
              name[i] = name[i + 1];
              i++;
            }
          name[i] = '\0';
        }
      i++;
    }
  return (name);
}

char    *parse_name2(char *arg, char *path, int i)
{
  char  *name;
  char	*path2;

  name = xcalloc((strlen(arg) + strlen(path) + 4), sizeof(char));
  path2 = xcalloc(((strlen(path) + 2) + strlen(arg) + 1), sizeof(char));
  arg = clean_arg(arg);
  if (arg[i - 1] != '/' && arg[i - 2] != '.' && arg[i - 3] != '.')
    {
      strcpy(path2, path);
      strcat(path2, "/");
      name = strcat(path2, arg);
      name = check_name(name);
    }
  else
    name = strdup(path);
  return (name);
}

char    *parse_name(char *arg, char *path)
{
  int   i;
  int   j;
  char  *name;

  printf("ARG = %s\n", arg);
  i = 0;
  j = strlen(path);
  while (arg[i])
    {
      if (arg[i] == '.' && arg[i + 1] == '.')
        {
          while (path[j] != '/' && j != 0)
            {
              printf("path = %s\n", path);
              path[j] = '\0';
              j--;
            }
          path[j] = '\0';
          printf("path = %s\n", path);
          i++;
        }
      i++;
    }
  name = parse_name2(arg, path, i);
  printf("name = %s\n", name);
  return (name);
}
