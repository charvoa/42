/*
** 42sh.h for 42sh in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:16:42 2014 garcia antoine
** Last update Thu May 22 18:45:54 2014 Nicolas Charvoz
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <stdio.h>
# include "./libsources/my.h"
# include "list.h"

typedef struct s_42sh
{
  t_dlist	*env;
  char		*cmd;
  char		**path;
  char		**envtab;
}		t_42sh;

extern	t_42sh	shell;

int	isolate_name_and_value_from_env(char *env);
char	*get_name_from_env(char *env);
char	*get_value_from_env(char *env);
char	*get_env(char *name, t_dlist *env);
char	**list_to_tab(t_dlist *env);
void    prompt(t_42sh*);
int	start_shell(t_42sh *shell);
int	init_my_shell(t_42sh *shell, char **env);
void	my_clear();
char	**strtotab(char*);
int	count_word(char*);
int	count_char(char*);
t_dlist *create_my_env(t_dlist *, char **);
int	check_builtins(t_42sh *, char**, t_dlist *);
int	my_cd(t_42sh *, char**, t_dlist *);
int	my_env(t_42sh *, char**, t_dlist *);
int	my_echo(t_42sh *, char**, t_dlist *);
int	my_exit(t_42sh *, char**, t_dlist *);
int	my_history(t_42sh *, char**, t_dlist *);
void	get_sigint(int);

#endif /*SHELL_H_ */
