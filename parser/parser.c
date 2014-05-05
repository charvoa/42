/*
** parser.c for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:34:31 2014 Nicolas Charvoz
** Last update Mon May  5 15:10:08 2014 Nicolas Charvoz
*/

#include "parser.h"

/* int     do_cmd(t_mini *mini) */
/* { */
/*   int   i; */
/*   int   status; */
/*   pid_t pid; */
/*   char  *pass; */

/*   if (check_builtin(mini) == 0) */
/*     return(0); */
/*   i = -1; */
/*   if ((pid = fork()) == -1) */
/*     exit(-1); */
/*   else if (pid == 0) */
/*     { */
/*       while (mini->tab[++i]) */
/*         { */
/*           pass = my_strcat(mini->tab[i], mini->current[0]); */
/*           if (execve(pass, mini->current, mini->env) != -1) */
/*             return(0); */
/*         } */
/*       my_printf("%s: Command not found\n", mini->current[0]); */
/*       exit(0); */
/*     } */
/*   else */
/*     wait(&status); */
/*   return (0); */
/* } */

/* void	send(char **tab) */
/* { */
/*   int	i; */

/*   i = 0; */
/*   while (tab[i]) */
/*     { */
/*       if (strcmp(tab[i], ";")) */
/* 	exec_comma(tab[i], tab[i + 1]); */
/*       i++; */
/*     } */
/* } */

char		*check_token(t_token **token, t_lex *lexi)
{
  t_token       *tok;

  tok = *token;
  if ((tok->type != TOKEN_WORD || tok->type == TOKEN_UNK) && (tok))
    return (tok->value);
  tok = tok->next;
  while (tok && tok->next)
    {
      if (tok->type == TOKEN_UNK)
  	{
  	  lexi->cmd[tok->pos - 1] = '\0';
	  tok->next =  NULL;
	  return (tok->value);
  	}
      if (tok->type != TOKEN_WORD && tok->next)
  	{
	  tok = tok->next;
  	  if (tok->type != TOKEN_WORD || tok->type == TOKEN_UNK)
  	    {
  	      lexi->cmd[tok->pos] = '\0';
	      tok->next = NULL;
	      return (tok->value);
  	    }
  	}
      tok = tok->next;
    }
  return (NULL);
}

int		size_of_list(t_token **token)
{
  t_token	*tok;
  int		i;

  i = 0;
  tok = *token;
  while (tok->next)
    {
      i++;
      tok = tok->next;
    }
  return (i);
}

void		parser(t_token **token)
{
  t_token	*tok;
  int		a;
  t_pars	*pars;

  a = 0;
  tok = *token;
  pars = malloc(sizeof(*pars));
  pars->tab = malloc((size_of_list(token) + 1) * sizeof(char*));
  pars->tab = memset(pars->tab, 0, (size_of_list(token) + 1));
  while (tok->next)
    {
      pars->tab[a] = malloc((strlen(tok->value) + 1) * sizeof(char));
      pars->tab[a] = memset(pars->tab[a], 0, (strlen(tok->value) + 1));
      pars->tab[a] = strdup(epur_str(tok->value));
      a++;
      tok = tok->next;
    }
  pars->tab[a] = malloc((strlen(tok->value) + 1) * sizeof(char));
  pars->tab[a] = memset(pars->tab[a], 0, (strlen(tok->value) + 1));
  pars->tab[a] = strdup(epur_str(tok->value));
  a++;
  pars->tab[a] = NULL;
  //send(pars->tab);
}
