/*
** 42sh.h for 42sh in /home/heitzl_s/42/env
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
<<<<<<< HEAD
** Started on  Sat May 24 00:17:45 2014 heitzl_s
** Last update Sat May 24 00:18:00 2014 heitzl_s
=======
** Started on  Fri Apr  4 12:16:42 2014 garcia antoine
<<<<<<< HEAD
** Last update Sat May 24 00:07:03 2014 Nicolas Girardot
=======
** Last update Thu May 22 18:45:54 2014 Nicolas Charvoz
>>>>>>> c40a3331e0f70987da71002b8a4680db772a89c4
>>>>>>> 8d6d32c84ecfc1dc298afa0055d7d7c8abcbeb5e
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
<<<<<<< HEAD
  char		*pwd_alias;
=======
  int		exit_value;
>>>>>>> 8d6d32c84ecfc1dc298afa0055d7d7c8abcbeb5e
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
