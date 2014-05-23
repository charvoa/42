/*
** main.c for 42sh in /home/heitzl_s/42/alias
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 00:49:48 2014 heitzl_s
** Last update Sat May 24 00:49:50 2014 heitzl_s
*/

#include "alias.h"

t_token		**alias(t_token **token, t_42sh *shell)
{
  int		fd;
  int		ret;
  char		*buffer;
  char		*final;
  char		**tab;
  t_alias	*list;

  if (shell->pwd_alias == NULL
      && (shell->pwd_alias = get_env("PWD", shell->env)) != NULL)
    {
      shell->pwd_alias = realloc(shell->pwd_alias, (strlen(shell->pwd_alias) + 13));
      strcat(shell->pwd_alias, "/alias/alias");
    }
  list = NULL;
  buffer = calloc(4096, sizeof(char));
  final = calloc(4096, sizeof(char));
  fd = open(shell->pwd_alias, O_RDONLY, O_APPEND);
  while ((ret = read(fd, buffer, 4096)) > 0)
    {
      final = realloc(final, strlen(buffer) + 4097);
      strcat(final, buffer);
      memset(buffer, 0, 4096);
    }
  tab = str_to_word_tab(final, '\n');
  make_list(tab, &list);
  token = check_list(&list, token);
  return (token);
}
