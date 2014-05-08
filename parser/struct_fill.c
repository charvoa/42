/*
** struct_fill.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu May  8 12:50:49 2014 Nicolas Charvoz
** Last update Thu May  8 17:18:52 2014 Nicolas Charvoz
*/

#include "parser.h"

void	init_struct(t_cmd *cmd)
{
  cmd->type = 0;
  cmd->status = 0;
  cmd->fdin = 0;
  cmd->fdout = 0;
}

void	fill_it(t_cmd *cmd, char *str, char *sep)
{
  parser2(str, cmd);
  if (sep != NULL)
    cmd->token = strdup(sep);
  else if (sep == NULL)
    cmd->token = NULL;
   if (sep != NULL)
     free(sep);
}

int             nbr_of_token(t_token **token)
{
  t_token       *tok;
  int           i;

  i = 0;
  tok = *token;
  while (tok->next != NULL)
    {
      if (tok->next != TOKEN_WORD)
        i++;
      tok = tok->next;
    }
  return (i);
}

void		struct_fill(char **tab, t_token **token, t_42sh *shell)
{
  t_cmd		*cmd;
  int		i;
  int		j;

  j = 0;
  i = 0;
  cmd = malloc((nbr_of_token(token) + 1) * sizeof(*cmd));
  while (tab[i])
    {
      if (tab[i + 1] == NULL)
	 {
	   fill_it(&cmd[j], tab[i], NULL);
	   global_exec(cmd, shell);
	   return ;
	 }
       else
	 {
	   fill_it(&cmd[j], tab[i], tab[i + 1]);
	   i += 2;
	   j += 1;
	 }
    }
  global_exec(cmd, shell, nbr_of_token(token));
  return ;
}
