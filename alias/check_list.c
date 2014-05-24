/*
** check_list.c for  in /home/charvo_a/42/alias
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat May 24 03:13:44 2014 Nicolas Charvoz
** Last update Sat May 24 03:17:56 2014 Nicolas Charvoz
*/

#include "alias.h"

char	**make_tab(char *str)
{
  char	**tab;
  int	j;
  int	i;
  int	a;

  a = 0;
  i = 0;
  tab = malloc((strlen(str) + 2) * sizeof(char*));
  j = 0;
  tab[a] = calloc((strlen(str) + 1), sizeof(char));
  while (str[i] != ' ' && str[i])
    {
      tab[a][j] = str[i];
      j++;
      i++;
    }
  tab[a] = '\0';
  a++;
  tab[a] = calloc((strlen(str) + 1), sizeof(char));
  tab[a] = &str[i];
  return (tab);
}

char	*copy_cmd(char *cmd, char *alias)
{
  char	**tab;
  char	*cmd_final;

  tab = NULL;
  tab = make_tab(cmd);
  tab[0] = NULL;
  tab[0] = strdup(alias);
  cmd_final = calloc((strlen(tab[0]) + strlen(tab[1]) + 2), sizeof(char));
  tab[0] = realloc(tab[0], (strlen(tab[0]) + strlen(tab[1]) + 2));
  cmd_final = strcat(tab[0], tab[1]);
  return (cmd_final);
}

t_token		**check_list(t_alias **alias, t_token **token)
{
  t_token	*tok;
  t_alias	*a;

  tok = *token;
  while (tok != NULL)
    {
      a = *alias;
      while (a)
	{
	  if (!(strncmp(a->ali[0], tok->value, strlen(a->ali[0]))))
	      tok->value = copy_cmd(tok->value, a->ali[1]);
	  a = a->next;
	}
      tok = tok->next;
    }
  return (token);
}
